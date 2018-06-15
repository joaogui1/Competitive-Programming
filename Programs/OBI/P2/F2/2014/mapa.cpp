#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int mark[100010];
long long int x;
vector <int> edges[100010];
void dfs(int a, int b){
   ++mark[a];
   ++x;
   for(int i = 0; i < edges[a].size(); ++i){
      if(!mark[edges[a][i]])dfs(edges[a][i], b);
   }
   return;
}
int main(){
   int a, b, c;
   long long int comp = 0, n;
   scanf("%lld", &n);
   for(int i = 1; i < n; ++i){
      scanf("%d %d %d", &a, &b, &c);
      if(c == 0){
         edges[a].push_back(b);
         edges[b].push_back(a);
      }
   }
   for(int i = 1; i <= n; ++i){
      x = 0;
      dfs(i, i);
      comp += x*(x-1)/2;
   }
   printf("%lld\n", n*(n - 1)/2 - comp);
   return 0;
}
