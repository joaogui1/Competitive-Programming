/*
ID: joaogui1
LANG: C++
TASK: comehome
*/
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
#define debug(a, b, c, d ,e)  std::cout << a << " " << b << " " << c << " " << d << " " << e
#define INF (1 << 30)
using namespace std;
int p, G[60][60], mark[60], dist[60];
map <char, int> mapa;
map <int, char> rev_mapa;
queue <int> q;
void djikstra(int cont){
   int davez = -1, mn = INF;
   while(1){
      davez = -1, mn = INF;
      for(int i = 0; i <= cont; ++i){
         if(!mark[i] && mn > dist[i]){
            davez = i;
            mn = dist[i];
         }
      }
      if(davez == -1) return;
      ++mark[davez];
      for(int i = 0; i <= cont; ++i)
         if(G[i][davez] && dist[i] > dist[davez] + G[i][davez])   dist[i] = dist[davez] + G[i][davez];

   }
}
int main(){
   int cont = 0, auxi, ansi = INF;
   char aux1, aux2, ansc;
   ifstream fin("comehome.in");
   ofstream fout("comehome.out");
   fin >> p;
   mapa.insert(make_pair('Z', 0));
   for(int i = 0; i < p; ++i){
      fin >> aux1 >> aux2 >> auxi;
      if(!mapa.count(aux1)){
          mapa.insert(make_pair(aux1, ++cont));
          rev_mapa.insert(make_pair(cont, aux1));
       }
      if(!mapa.count(aux2)){
          mapa.insert(make_pair(aux2, ++cont));
          rev_mapa.insert(make_pair(cont, aux2));
      }
      if(aux1 != aux2 && (G[mapa[aux1]][mapa[aux2]] == 0 || auxi < G[mapa[aux1]][mapa[aux2]]))  G[mapa[aux1]][mapa[aux2]] = G[mapa[aux2]][mapa[aux1]] = auxi;
   }
   for(int i = 1; i <= cont; ++i)   dist[i] = INF;
   djikstra(cont);
   for(int i = 1; i <= cont; ++i)
      if('A' <= rev_mapa[i] && rev_mapa[i] <= 'Z' && dist[i] < ansi){
         ansi = dist[i];
         ansc = rev_mapa[i];
      }
   fout << ansc << " " << ansi << endl;
   return 0;
}
