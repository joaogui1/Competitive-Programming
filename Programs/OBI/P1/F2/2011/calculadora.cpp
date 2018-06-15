#include <cstdio>
int numbers[10];
int main(){
   int ans = 1, n, aux;
   char op;
   scanf("%d", &n);
   while(n--){
      scanf("%d %c", &aux, &op);
      if(op == '*'){
         if(aux == 2 || aux == 3 || aux == 5 || aux == 7)   ++numbers[aux];
         if(aux == 4)   numbers[2] += 2;
         if(aux == 8)   numbers[2] += 3;
         if(aux == 6){
             ++numbers[2];
             ++numbers[3];
         }
         if(aux == 9)   numbers[3] += 2;
      }
      else{
         if(aux == 2 || aux == 3 || aux == 5 || aux == 7)   --numbers[aux];
         if(aux == 4)   numbers[2] -= 2;
         if(aux == 8)   numbers[2] -= 3;
         if(aux == 6){
             --numbers[2];
             --numbers[3];
         }
         if(aux == 9)   numbers[3] -= 2;
      }
   }
   for(int i = 2; i < 10; ++i){
      while(numbers[i]--)
         ans*=i;
   }
   printf("%d\n", ans);
   return 0;
}
