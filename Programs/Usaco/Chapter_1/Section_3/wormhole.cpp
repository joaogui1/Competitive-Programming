/*
ID: joaogui1
LANG: C++
TASK: wormhole
*/
#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
//#define Pair(x,  x + i) pares += 2; p[x + i] = x; p[x] = x + i
using namespace std;
int n, p[20],ans, aux1, aux2, pares, Right[20];
map <int, pair <int,int> > mapa;
void has_cycle(){
   for (int start=1; start <= n; ++start) {
      int pos = start;
      for (int count=0; count < n; ++count)  pos = Right[p[pos]];
      if (pos != 0) {
         ++ans;
         return;
      };
   }
   return;
}
void pairings(int x){
   for(int i = 1; i <= n - x; ++i){
      if(p[x + i] == 0){ // checa se nao tem par
         pares += 2;
         p[x + i] = x;
         p[x] = x + i;
         if(pares == n) has_cycle();
         else for(int j = 1; j <= n; ++j) //procura cara livre
            if(p[j] == 0){
               pairings(j);
               break;
            }
         pares -= 2; //desfaz os pares
         p[x + i] = p[x] = 0;
      }
   }
   return;
}
int main(){
   ifstream fin ("wormhole.in");
   ofstream fout ("wormhole.out");
   fin >> n;
   for(int i = 1; i <= n; ++i){
      fin >> aux1;
      fin >> aux2;
      mapa.insert(make_pair(i, make_pair(aux1, aux2)));
  }
   for(int i = 1; i <= n; ++i ) //define o cara a direita
      for(int j = 1; j <= n; ++j)
         if(mapa[j].second == mapa[i].second && mapa[j].first > mapa[i].first)
            if(Right[i] == 0 || mapa[j].first < mapa[Right[i]].first)
               Right[i] = j;

   pairings(1);
   fout << ans << endl;
   return 0;
}
