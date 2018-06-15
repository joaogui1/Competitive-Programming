#include "ckollib.h"
#include <bits/stdc++.h>

using namespace std;
//map <int, int> mp;
int bits[32];

int main(){
  int a = -1, fra = 0, b = -1, frb = 0, aux;
  while(1){
    aux = karta();
    if(aux == 0)  break;
    if(a == -1) a = aux;
    if(b == -1 && a != aux) b = aux;
    if(a == aux) ++fra;
    if(b == aux) ++frb;
    for(int i = 0; i < 31; ++i)
      if(aux&(1 << i))
        ++bits[i];
  }
  if(b == -1){
    odpowiedz(a);
    return 0;
  }
  if(fra < frb){
    odpowiedz(a);
    return 0;
  }
  else if(fra < frb){
    odpowiedz(b);
    return 0;
  }
  for(int i = 0; i < 31; ++i) bits[i] %= fra;
  a = 0;
  for(int i = 0; i < 31; ++i)
    if(bits[i])
      a += (1 << i);
  odpowiedz(a);


  return 0;
}
