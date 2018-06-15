#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int kad[500100];
int main(){
   int n, sum = 0, best = 0;
   scanf("%d", &n);
   for(int i = 0; i < n; ++i)
      scanf("%d", &kad[i]);
   for(int i = 0; i < n; ++i){
      sum += kad[i];
      if(sum < 0) sum = 0;
      if(sum > best) best = sum;
   }
   printf("%d\n", best);


   return 0;
}
