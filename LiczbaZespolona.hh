#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

struct LZ{
  double re;
  double im;
};

std:: ostream& operator<<(std::ostream& s, const LZ& lz);
// przeciazenie operatora do wypysiwania liczby zespolonej

std:: istream&  operator>>(std::istream& input, LZ& lz);
// przeciazenie operatora wczytywania liczby zespolonej

LZ operator+(const LZ& lz1, const LZ& lz2);

LZ operator-(const LZ& lz1, const LZ& lz2);

LZ operator*(const LZ& lz1, const LZ& lz2);

LZ sprzezenie(const LZ& lz);

LZ operator/(const LZ& lz1, double liczba);

LZ operator/(const LZ& lz1, const LZ& lz2);

bool operator==(LZ& lz1, LZ& lz2);

double potega_kwadrat(double liczba);

double modul_kwadrat(const LZ& lz);


 
