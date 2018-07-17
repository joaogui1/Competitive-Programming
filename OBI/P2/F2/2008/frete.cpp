#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;
int pai[1010];
int find(int x){
   if(x == pai[x])   return x;
   return pai[x] = find(pai[x]);
}
void join(int x, int y){
   pai[find(x)] = find(y);
   return;
}
vector < pair <int, pair <int, int> > > edges;
int main(){
   int ans = 0, n, e, a, b, c;
   scanf("%d %d", &n, &e);
   for(int i = 1; i <= n; ++i)   pai[i] = i;
   for(int i = 0; i < e; ++i){
      scanf("%d %d %d", &a, &b, &c);
      edges.push_back(make_pair(c, make_pair(a, b)));
   }
   sort(edges.begin(), edges.end());
   for(int i = 0; i < e; ++i){
      if(find(edges[i].second.first) != find(edges[i].second.second)){
         join(edges[i].second.first, edges[i].second.second);
         ans += edges[i].first;
      }
   }
   printf("%d\n", ans);
   return 0;
}
