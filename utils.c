/*******************************************************************************
 * Name        : utils.c
 * Author      : Cormac Taylor
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include "utils.h"

int cmpr_int(void* x, void* y) {

    int val_x = *( (int*) x );
    int val_y = *( (int*) y );

    if (val_x > val_y) {
        return 1;
    } else if (val_x < val_y) {
        return -1;
    } else {
        return 0;
    }
}

int cmpr_float(void* x, void* y) {

    float val_x = *( (float*) x );
    float val_y = *( (float*) y );
    
    if (val_x > val_y) {
        return 1;
    } else if (val_x < val_y) {
        return -1;
    } else {
        return 0;
    }
}

void print_int(void* x){
    printf("%d ", *( (int*) x ));
}

void print_float(void* x){
    printf("%f ", *( (float*) x ));
}