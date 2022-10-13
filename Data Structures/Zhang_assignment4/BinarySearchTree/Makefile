CC = g++
CCFLAGS = -Wall -g

main: main.o BinaryTree.o
	$(CC) $(CCFLAGS) -o main main.o BinaryTree.o
main.o: main.cpp
	$(CC) $(CCFlAGS) -c main.cpp
BinaryTree.o: BinaryTree.cpp
	$(CC) $(CCFLAGS) -c BinaryTree.cpp

clean:
	rm main main.o BinaryTree.o 