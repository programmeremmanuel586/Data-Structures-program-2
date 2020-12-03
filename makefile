CXXFLAGS=-Wall -Wextra -pedantic -g -std=c++17
CXX=clang++
LINK.o=$(LINK.cc)

main: main.o Game.o Item.o PayoutTable.o SlotMachine.o 

clean:
	rm -f *.o main
