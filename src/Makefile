CFLAGS = -std=c++11

all: abstractvm

abstractvm:avm.o main.o
	$(CXX) $(CFLAGS) avm.o main.o -o abstractvm

main.o: main.cpp
	$(CXX) $(CFLAGS)	-c main.cpp

avm.o: avm.cpp avm.hpp
	$(CXX) $(CFLAGS)	-c avm.cpp
clean:
	rm -f *.o $(NAME)