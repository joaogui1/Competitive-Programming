#include <cstdio>

int main(){
   int a, n, f, ans = 0;
   scanf("%d %d", &a, &n);
   for(int i = 0; i < n; ++i){
      scanf("%d", &f);
      if(f*a >= 40000000)  ++ans;
   }
   printf("%d\n", ans);

   return 0;
}
