CC = g++
CCFlAGS = -Wall -g

main: main.o Student.o Instructor.o
	$(CC) $(CCFLAGS) -o main main.o Student.o Instructor.o
main.o: main.cpp Student.h Instructor.h
	$(CC) $(CCFLAGS) -c main.cpp
Student.o: Student.cpp Student.h
	$(CC) $(CCFLAGS) -c Student.cpp
Instructor.o: Instructor.cpp Instructor.h
	$(CC) $(CCFLAGS) -c Instructor.cpp

clean:
	rm main main.o Student.o Instructor.o
