#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int pai[510];
vector <pair<int, pair<int, int> > > edges;

int find(int x){
   if(x == pai[x])   return x;
   return pai[x] = find(pai[x]);
}

void join(int x, int y){
   pai[find(x)] = find(y);
   return;
}

int main(){
   int m, n, u, v, c, sz, ans = 0;
   scanf("%d %d", &n, &m);
   for(int i = 1; i <= n; ++i)   pai[i] = i;
   for(int i = 0; i < m; ++i){
      scanf("%d %d %d", &u, &v, &c);
      edges.push_back(make_pair(c, make_pair(u, v)));
   }
   sort(edges.begin(), edges.end());
   sz = edges.size();
   for(int i = 0; i < sz; ++i)
      if(find(edges[i].second.first) != find(edges[i].second.second)){
         join(edges[i].second.first, edges[i].second.second);
         ans += edges[i].first;
      }
   printf("%d\n", ans);

   return 0;
}
