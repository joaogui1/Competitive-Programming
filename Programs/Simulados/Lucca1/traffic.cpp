#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#define INF 1 << 29
using namespace std;
int n, cities[1024];
vector viz[102]
int main(){
   int aux, auy, ind, sum, best = 1 << 29, sum_tot, sum_left, sum_right;
   scanf("%d", &n);
   for(int i = 0; i < n; ++i)
      scanf("%d", &cities[i]);
   for(int i = 0; i < n-1; ++i)
      scanf("%d%d", &aux, &auy);
   for(int i = 0; i < n; ++i){
      sum = sum_tot = sum_left = sum_right 0;
      for(int j = i + 1; j < n; ++j){
         sum_left += cities[j];
      }
      for(int j = i - 1; j < n; ++j){
         sum_right += cities[j];
      }
      sum = max(sum_right, sum_left);
      if(sum < best){
          best = sum;
          ind = i;
       }
   }
   printf("%d\n", ind);
   return 0;
}
