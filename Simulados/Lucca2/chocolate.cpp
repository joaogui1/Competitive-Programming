#include <cstdio>
int mov[1000100], count[1000100];
void ans(int n, int m){
   for(int i = 0; i <= n; ++i){
      if(count[i] == 0)
         for(int j = 1; j <= m; ++j){
            ++count[i + j];
            mov[i + j] = j; //movimento que pode ser usado para ganhar
         }
      else if(count[i] == 1){
         ++count[i + mov[i]]; //bloquei a forma de ganhar estando em i
         mov[i + mov[i]] = mov[i];
      }
   }
   return;
}
int main(){
   int n, m;
   scanf("%d %d", &n, &m);
   ans(n, m);
   printf("%s\n", (count[n])?"Paula":"Carlos");

   return 0;
}
