#include "WyrazenieZespolone.hh"
  
std:: istream& operator>>(std::istream& input, WZ& WyZesp){
  bool Blad=false;
  input>>WyZesp.LiczbaZesp1;
  if(input.fail()){
    input.clear();
    Blad=true;}

  input>>WyZesp.Oper;
  if(input.fail()){
    Blad=true;}
  input>>WyZesp.LiczbaZesp2;
  if(input.fail()) Blad=true;

  if(Blad) input.setstate(input.failbit);

  return input;
}

std::ostream& operator<<(std::ostream& output, const WZ& WyZesp){
  std::cout<<WyZesp.LiczbaZesp1<<WyZesp.Oper<<WyZesp.LiczbaZesp2<<std::endl;
  return output;
} // Przeciazenie operatora do wyswietlania wyrazenia zespolonego

oper Konwerter(char op){
  switch(op){
  case '+': return O_D;
  case '-': return O_O;
  case '*': return O_M;
  case '/': return O_Dz;
  }
  return O_D;
}

std::ostream& operator<<(std::ostream& s, const oper op){
  const char* t="+-*/";
  s<<t[op];
  return s;
} // Przeciazenie do wyswietlania operatora zdefiniowanego w typie wyliczeniowym enum

std::istream& operator>>(std::istream& input, oper& op){
  // Przeciazenie operatora wczytwania operatora zdefiniowanego w typie wyliczeniowym
  char Tymcz;
  input>>Tymcz;
  op=Konwerter(Tymcz);
  return input;
}

bool Wynik(const WZ& WyZesp, LZ& wynik){
  
  switch (WyZesp.Oper)
  {
  case O_D:
    wynik=WyZesp.LiczbaZesp1+WyZesp.LiczbaZesp2;
    break;
  case O_O:
    wynik=WyZesp.LiczbaZesp1-WyZesp.LiczbaZesp2;
    break;
  case O_M:
    wynik=WyZesp.LiczbaZesp1*WyZesp.LiczbaZesp2;
    break;
  case O_Dz:
    if (!modul_kwadrat(WyZesp.LiczbaZesp2)) return false;
    wynik=WyZesp.LiczbaZesp1/WyZesp.LiczbaZesp2;
    break;
  }

  return true;
}


  
  


