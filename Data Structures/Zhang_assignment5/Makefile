CC = g++
CCFLAGS = -Wall -g

main: main.o SortingAlgo.o
	$(CC) $(CCFLAGS) -o main main.o SortingAlgo.o
main.o: main.cpp
	$(CC) $(CCFlAGS) -c main.cpp
main2: main2.o SortingAlgo.o
	$(CC) $(CCFLAGS) -o main2 main2.o SortingAlgo.o
main2.o: main2.cpp
	$(CC) $(CCFLAGS) -c main2.cpp
SortingAlgo.o: SortingAlgo.cpp
	$(CC) $(CCFLAGS) -c SortingAlgo.cpp

clean:
	rm main main.o
clean2:
	rm main2 main2.o
cleanSort:
	rm SortingAlgo.o
