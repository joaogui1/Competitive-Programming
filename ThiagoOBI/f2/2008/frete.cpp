#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

int p[1010];
vector <pip> edges;
int find(int x){
  return (x == p[x])?(x):(p[x] = find(p[x]));
}

void join(int x, int y){
  p[find(y)] = find(x);
}

int main(){
  int n, m, u, v, w, ans = 0;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i)  p[i] = i;
  for(int i = 0; i < m; ++i){
    scanf("%d %d %d", &u, &v, &w);
    edges.push_back(pip(w, pii(u, v)));
  }
  sort(edges.begin(), edges.end());
  for(int i = 0; i < edges.size(); ++i){
    u = edges[i].ss.ff, v = edges[i].ss.ss, w = edges[i].ff;
    if(find(u) != find(v)){
      ans += w;
      join(u, v);
    }
  }
  printf("%d\n", ans);
  return 0;
}
