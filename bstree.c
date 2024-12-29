/*******************************************************************************
 * Name        : bstree.c
 * Author      : Cormac Taylor
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include "bstree.h"

void create_node(void* val, size_t size, node_t** node_ptr) {

    (*node_ptr) = (node_t*) malloc(size + 2 * sizeof(node_t*));

    (*node_ptr)->data = (void*) malloc(size);
    (*node_ptr)->left = NULL;
    (*node_ptr)->right = NULL;

    for(int i = 0; i < size; i++){
        *((char*)((*node_ptr)->data) + i) = *((char*)val + i);
    }
}

void add_node(void* val, size_t size, tree_t* t, int (*cmpr)(void*,void*)) {

    if(t->root == NULL) {
        create_node(val, size, &(t->root));
    } else {
        node_t* cur_node = t->root;
        while(cur_node->left != NULL || cur_node->right != NULL){
            
            if(cmpr(val,cur_node->data) == -1){
                if(cur_node->left != NULL){
                    cur_node = cur_node->left;
                } else {
                    break;
                }
            } else {
                if(cur_node->right != NULL){
                    cur_node = cur_node->right;
                } else {
                    break;
                }
            }
        }
        if(cmpr(val,cur_node->data) == -1){
            create_node(val, size, &(cur_node->left));
        } else {
            create_node(val, size, &(cur_node->right));
        }
    }
}

void print_tree(node_t* node, void (*print)(void*)){

    if(node != NULL){
        print_tree(node->left, print);
        print(node->data);
        print_tree(node->right, print);
    }
}

void destroy_nodes(node_t** node){

    if((*node) != NULL){
        destroy_nodes(&((*node)->left));
        destroy_nodes(&((*node)->right));
        free((*node)->data);
        (*node)->data = NULL;
        free(*node);
        (*node) = NULL;
    }
}

void destroy(tree_t* t){

    if(t != NULL){
        destroy_nodes(&(t->root));
    }
}



// sizeof(node_t*) is good right?
// print_tree calling util functions which cast to int/float ptrs is good right?
