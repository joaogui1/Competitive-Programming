#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
int donuts[20010];
int main(){
   int t, n, aux, ans, cont, m;
   scanf("%d", &t);
   while(t--){
      memset(donuts, 0, sizeof(donuts));
      ans = 0;
      cont = aux = 0;
      scanf("%d %d", &n, &m);
      for(int i = 0; i < m; ++i)
         scanf("%d", &donuts[i]);

      sort(donuts, donuts + m);
      for(int i = m - 1; i >= cont; --i)
           if(donuts[i] <= n){
             n -= donuts[i];
             m = i;
             break;
          }
      for(int i = m - 1, j = 0; i >= j && (n > 0); --i){
         ++ans;
         n -= (donuts[i] + 1);
         if(--donuts[j] == 0) ++j;
      }
      printf("%d\n", ans);

   }



   return 0;
}
