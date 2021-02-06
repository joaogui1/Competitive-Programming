#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define INF 1 << 30
using namespace std;
pair <int, int> indios[1100];
bool toras[1001100];
int cycle(int x, int n){
   return ((x%n)+n)%n;
}
int main(){
   int n, k, bat = 0, best = -1, tora, sentido;
   bool vdc = 0;
   scanf("%d %d", &n, &k);
   for(int i = 0; i < k; ++i){
      scanf("%d %d", &tora, &sentido);
      ++toras[--tora];
      indios[i].first = tora;
      indios[i].second = sentido;
   }
   sort(indios, indios + k);
   for(int i = 1; i < k; ++i){
      vdc = 1;
      int cont = 0;
      bat = indios[i].first - indios[0].first;
      if(indios[0].second == -1) bat = n - bat;
      for(int j = 0; j < k; ++j){
         int new_pos = cycle(indios[j].first + indios[j].second*bat, n);
         if(toras[new_pos] != 1){
              vdc = false;
              break;
         }
         ++cont;
      }
      if(vdc && cont == k)
         if(best == -1 || bat < best)   best = bat;
   }
   if(best == -1) best = n;
   printf("%d\n", best);
   return 0;
}
