#include <cstdio>
#include <algorithm>
int main(){
   float notas[5] = {0};
   for(int i = 0; i < 5; ++i)
      scanf("%f", &notas[i]);
   std::sort(notas, notas + 5);
   printf("%0.1f\n", (notas[1] + notas[2] + notas[3]));

   return 0;
}
