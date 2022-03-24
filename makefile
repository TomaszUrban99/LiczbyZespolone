FLAGS= -Wall -pedantic -std=c++17 -iquote inc

main: main.cpp  WyrazenieZespolone.o LiczbaZespolona.o Statystyka.o
	g++ ${FLAGS} main.cpp WyrazenieZespolone.o LiczbaZespolona.o Statystyka.o

Statystyka.o: Statystyka.cpp Statystyka.hh
	g++ -c ${FLAGS} Statystyka.cpp

WyrazenieZespolone.o: WyrazenieZespolone.cpp WyrazenieZespolone.hh LiczbaZespolona.hh
	g++ -c ${FLAGS} WyrazenieZespolone.cpp

LiczbaZespolona.o: LiczbaZespolona.cpp LiczbaZespolona.hh
	g++ -c ${FLAGS} LiczbaZespolona.cpp

