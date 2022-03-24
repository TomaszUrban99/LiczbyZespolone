#include "LiczbaZespolona.hh"
#include "Statystyka.hh"

std:: ostream& operator<<(std::ostream& output, ST& stat){
  int Wynik=0; // Procentowy udzial poprawnych odpowiedzi
  output<<"Odpowiedzi poprawne: "<<stat.Prawda<<"."<<std::endl;
  output<<"Odpowiedzi falszywe: "<<stat.Falsz<<"."<<std::endl;
  Wynik=(stat.Prawda*100)/(stat.Prawda+stat.Falsz);
  output<<"Twoj wynik procentowy: "<<Wynik<<"%"<<std::endl;
  return output;
}

void Zerowanie(ST& stat){
  stat.Prawda=0;
  stat.Falsz=0;
}
/* Funkcja do wyzerowania licznikow poprawnych i zlych */

ST PorownanieStatystyka(ST& stat, const bool odpowiedz){
  if(odpowiedz) ++stat.Prawda;
  else ++stat.Falsz;

  return stat;
}

