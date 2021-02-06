#include <cstdio>
int freq[110];
int main(){
   int n, aux, ans = 0, best = 0;
   scanf("%d", &n);
   while(n--){
      scanf("%d", &aux);
      ++freq[aux];
   }
   for(int i = 0; i <= 100; ++i)
      if(freq[i] >= best){
         best = freq[i];
         ans = i;
      }
   printf("%d\n", ans);
   return 0;
}
