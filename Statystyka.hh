#include <iostream>
#include <fstream>

struct ST{
  int Prawda;
  int Falsz;
};

std:: ostream& operator<<(std::ostream& output, ST& stat);

void Zerowanie(ST& stat);

ST PorownanieStatystyka(ST& stat, const bool odpowiedz);