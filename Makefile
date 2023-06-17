all: run clean

run: blackjack.o
	./blackjack.o

blackjack.o: blackjack.cpp
	g++ -o blackjack.o blackjack.cpp -std=c++17


clean:
	rm -f *.o

.PHONY: all run