#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#define INF long long int(1) << 49
using namespace std;
int n, R[100010];
int main(){
   long long int r, b, l, aux, davez, best = 0, test = 1, cost;
   scanf("%lld%lld%lld", &r, &l, &b);
   for(int i = 0; i < r; ++i)
      scanf("%d", &R[i]);
   davez = r/2;
   double t = clock();
   while(1){
      cost = 0;
      int esq =  davez - 1,dir = davez + 1;
      while(cost < b){
         cout << test << endl;
         if(R[davez] - R[esq] + cost > b && R[dir] - R[davez] + cost > b)  break;
         if(R[davez] - R[esq] < R[dir] - R[davez]){
            cost += R[davez] - R[esq--];
            ++test;
         }
         else{
            cost += R[dir++] - R[davez];
            ++test;
         }
         if(esq == 0 || dir == r)   break;
      }
      best = max(best, test);

   }
   printf("%lld\n", best);
   return 0;
}
