#pragma once
#include <iostream>
#include <fstream>
#include "LiczbaZespolona.hh"

enum oper{ O_D, O_O, O_M, O_Dz};

struct WZ{ // struktura do zapisywania wyrazenia zespolonego
  LZ LiczbaZesp1;
  LZ LiczbaZesp2;
  oper Oper;
};

std::istream& operator>>(std::istream& input, WZ& WyZesp);

std::istream& operator>>(std::istream& input, oper& Op);

std::ostream& operator<<(std::ostream& output, const WZ& WyZesp);

std::ostream& operator<<(std::ostream& s, const oper op);

oper Konwerter(char op);

bool Wynik(const WZ& WyZesp, LZ& wynik);
