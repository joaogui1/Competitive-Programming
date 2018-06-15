#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 10010

using namespace std;

int input[MAXN];
vector <int> best;
vector <int> lis;
int main(){
   int n, aux;
   scanf("%d", &n);
   for(int i = 1; i <= n; ++i)   scanf("%d", &input[i]);
   for(int i = 1; i <= n; ++i){
      aux = input[i];
      if(!best.size())  best.push_back(aux);
      if(aux > best.back()){
           best.push_back(aux);
           lis.push_back(best[best.size() - 2]);
      }

      else
         *lower_bound(best.begin(), best.end(), aux) = aux;

   }
   lis.push_back(best.back());
   printf("%d\n", (int)best.size());
   for(int i = 0; i < lis.size(); ++i) printf("%d ", lis[i]);
   printf("\n");
   return 0;
}
