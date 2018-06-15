#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define SET(obj, a) memset(obj, a, sizeof(obj))
#define INF 0x3f3f3f3f
using namespace std;
int paes[10010], k, m;
bool da_certo(int n){
   int cont = 0;
   for(int i = 0; i < k; ++i)
      cont += paes[i]/n;
   return cont >= m;
}
int bin_search(int q){
   int fim = q, ini = 1, med;
   bool a, b;
   while(fim - ini > 1){
      med = (ini + fim)/2;
      //cout << med << endl;
      a = da_certo(med);
      b = da_certo(med + 1);
      if(a && !b) return med;
      if(!a && !b)   fim = med;
      else if(a && b)   ini = med;
   }
   return ini;
}
int main(){
   int max_s = 0,ans, sum = 0;
   scanf("%d %d", &m, &k);
   for(int i = 0; i < k; ++i){
      scanf("%d", &paes[i]);
      max_s = max(max_s, paes[i]);
      sum += paes[i];
   }
   //cout << "ok" << endl;
   ans = bin_search(max_s);
   if(sum < m) ans = 0;
   printf("%d\n", ans);
   return 0;
}
