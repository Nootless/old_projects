CC = g++
CCFlAGS = -Wall -g

main: main.o ItemType.o SortedLinkedList.o 
	$(CC) $(CCFLAGS) -o main main.o ItemType.o SortedLinkedList.o
main.o: main.cpp  
	$(CC) $(CCFLAGS) -c main.cpp 
ItemType.o: ItemType.cpp  
	$(CC) $(CCFLAGS) -c ItemType.cpp
SortedLinkedList.o: SortedLinkedList.cpp 
	$(CC) $(CCFLAGS) -c SortedLinkedList.cpp

clean:
	rm main main.o ItemType.o SortedLinkedList.o
