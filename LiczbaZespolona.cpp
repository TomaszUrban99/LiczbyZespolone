#include "LiczbaZespolona.hh"

std::ostream& operator<<(std::ostream& s, const LZ& lz){
  s<<"("<<lz.re << std::showpos << lz.im << std::noshowpos << "i)";
    return s;
    }

std::istream& operator>>(std::istream& input, LZ& lz){
    char temp;
    char temp2; // zmienne pomocnicza do przechowywania pobranych znakow 
    double Skladowa; // pomocnicza zmienna do przechowywania skladoych liczby zespolonej
    bool Blad=false; // zmienna pomocnicza do ustalenia, czy pod wzgledem formy liczba jest poprawna

    input>>temp; // pobranie pierwszego znaku z wejscia input

    if(temp!='(') return input; // jezeli pierwszy pobrany znak nie bedzie nawiasem, 
                                // przeciazenie zwraca strumien
    input>>temp; // po pobranym nawiasie otwierajacym pobierany jest kolejny znak 

    while (temp!='i'&& temp!=')'){
        if(isdigit(temp)||'+'||'-'){
            
            input>>temp2;
    
            if(temp2=='i'){
                input.putback(temp2);
                input.putback('1');
                input.putback(temp);
                input>>Skladowa;
                input>>temp;
                }
            else{
                if (isdigit(temp2)){
                    input.putback(temp2);
                    input.putback(temp); // jezeli pobrano znak liczbowy, zwroc pobrany 
                    input>>Skladowa; // pobranie i zapisanie w zmiennej typu double (Skladowa)// pobranie i sprawdzenie poprawnosci kolejnego znaku
                    input>>temp;}
                else{
                    if(!isdigit(temp)&&(temp2=='+'||temp2=='-')){
                        temp=temp2;
                        Blad=true;}
                    else{
                    if(!isdigit(temp2)&&(temp=='-'||temp=='+')){
                        temp=temp2;
                        input>>temp;
                        Blad=true;}
                    else{
                        input.putback(temp2);
                        input.putback(temp); // jezeli pobrano znak liczbowy, zwroc pobrany 
                        input>>Skladowa; // pobranie i zapisanie w zmiennej typu double (Skladowa)// pobranie i sprawdzenie poprawnosci kolejnego znaku
                        input>>temp;}}
                    }}} 
            else{
                input>>temp;
                Blad=true; }
        
        if(temp=='i') lz.im=Skladowa;
        else{
            if(temp=='+'||temp=='-'||temp==')'){
                lz.re=Skladowa;
                if(temp==')') lz.im=0;
                input.putback(temp);}
            else Blad=true;}

        input>>temp;
        } // pobranie i sprawdzenie kolejnego znaku

        if(Blad) input.setstate(input.failbit);
    return input;
}

LZ operator+(const LZ& lz1, const LZ& lz2){
  /* przeciazenie operatora dodawania dla liczb zespolonych */
  return {lz1.re+lz2.re, lz1.im+lz2.im};
}

LZ operator-(const LZ& lz1, const LZ& lz2){
  /* przeciazenie operatora odejmowania dla liczb zespolonych */
  return {lz1.re-lz2.re, lz1.im-lz2.im};
}

LZ operator*(const LZ& lz1, const LZ& lz2){
  /* przeciazenie operatora mnozenia dla liczb zespolonych */
  return {(lz1.re*lz2.re)-(lz1.im*lz2.im), (lz2.im*lz1.re)+(lz1.im*lz2.re)};
}

double potega_kwadrat(double liczba){
  /* funkcja potega: funkcja zwracajaca  */
  /* kwadrat podanej liczby rzeczywistej */
  /* typ zwracanej wartości: double      */
  return liczba*liczba;
}

double modul_kwadrat(const LZ& lz){
  /* funkcja modul: funkcja zwracajaca */
  /* modul liczby zespolonej           */
  /* typ zwracanej wartości: double    */
  return potega_kwadrat(lz.re)+potega_kwadrat(lz.im);
}
    
LZ sprzezenie(const LZ& lz){
  /* funkcja sprzezenie: funkcja zwracajaca */
  /* sprzezenie podanej liczby zespolonej   */
  return {lz.re, (-1)*lz.im};
}

LZ operator/(const LZ& lz1, double liczba){
  /* przeciazenia operatora dzielenia dla dzielenia liczby */
  /* zespolonej przez liczbe rzeczywista                   */
  /* warunkiem wstepnym jest wartosc argumentu liczba      */
  /* rozna od zera                                         */
  /* jezeli liczba bedzie rowna zero to                    */
  return {lz1.re/liczba, lz1.im/liczba};
}

LZ operator/(const LZ& lz1, const LZ& lz2){
  /* przeciazenie operatora dzielenia dla dwoch liczb */
  /* zespolonych. */
  return (lz1*sprzezenie(lz2))/modul_kwadrat(lz2);
}

bool operator==(LZ& lz1, LZ& lz2){
  return ((lz1.re==lz2.re)&&(lz1.im==lz2.im));
}