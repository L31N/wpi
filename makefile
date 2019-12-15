PROG = abgabeaufgabe

FLAGS = -O2 -std=c++11 

CC = g++

SRCS = MyQuaternion.cpp main_aufgabe2.cpp MyFunctions.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(SRCS) $(PROG)

$(PROG): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC)  $(FLAGS) -c $<

clean:
	rm -rf *.o $(PROG)

## dependencies

MyQuaternion.o: MyQuaternion.cpp MyQuaternion.h 
MyFunctions.o: MyFunctions.cpp MyQuaternion.h MyFunctions.h 

main_aufgabe2.o: main_aufgabe2.cpp MyQuaternion.h MyFunctions.h 