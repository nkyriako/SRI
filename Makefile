OBJS = main.o Fact.o Rule.o KB.o RB.o Query.o
#query.o
CC = g++
DEBUG = -g
CFLAGS = -std=c++14 -Wall -c $(DEBUG)
LFLAGS = -std=c++14 -Wall $(DEBUG)

#put rest of main functions in all to compile everything
all:main

main : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main

Fact.o : Fact.h Fact.cpp 
	$(CC) $(CFLAGS) Fact.cpp

main.o : 
	$(CC) $(CFLAGS) main.cpp

Rule.o : Rule.h Rule.cpp 
	$(CC) $(CFLAGS) Rule.cpp
KB.o : KB.h KB.cpp
	$(CC) $(CFLAGS) KB.cpp
RB.o : RB.h RB.cpp
	$(CC) $(CFLAGS) RB.cpp

Query.o : Query.h Query.cpp
	$(CC) $(CFLAGS) Query.cpp
clean:
	rm -f *.o main


program1:
	./main

	
