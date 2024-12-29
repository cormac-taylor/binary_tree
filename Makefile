all: main.o utils.o bstree.o
	@echo "* Linking all objects..."
	gcc $^ -o a.out

main.o: main.c
	@echo "* Compiling main.c..."
	gcc main.c -c

utils.o: utils.c
	@echo "* Compiling utils.c..."
	gcc utils.c -c

bstree.o: bstree.c
	@echo "* Compiling bstree.c..."
	gcc bstree.c -c

clean:
	@echo "Cleaning up..."
	rm *.o
