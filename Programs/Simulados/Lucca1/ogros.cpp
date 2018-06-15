#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#define INF 1 << 29
using namespace std;
int n, m;
int faixas[10010], ogros[10010], premios[10010];

int Bin_search(int val){
   int ini = 0, fim = n;
   while(fim - ini > 1){
      int med = (ini + fim)/2;
      if(faixas[med] <= val) ini = med;
      else  fim = med;
   }
   return premios[fim - 1];
}

int main(){
   scanf("%d%d", &n, &m);
   faixas[0] = 0;
   for(int i = 1; i < n; ++i)
      scanf("%d", &faixas[i]);
   for(int i = 0; i < n; ++i)
      scanf("%d", &premios[i]);
   for(int i = 0; i < m; ++i)
      scanf("%d", &ogros[i]);
   for(int i = 0; i < m; ++i){
      printf("%d", Bin_search(ogros[i]));
      if(i != m-1)   printf(" ");
      else  printf("\n");
   }



   return 0;
}
