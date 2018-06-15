#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

vector <pip> edges;
int p[128], r[128];

int find(int x){
  return (x == p[x])?x:p[x] = find(p[x]);
}

void join(int x, int y){
  x = find(x), y = find(y);
  if(r[x] > r[y]) p[y] = x;
  else{
    p[x] = y;
    if(r[x] == r[y])  ++r[y];
  }
  return;
}

int main(){
  int n, f, rr, a, b, c, ans = 0;
  scanf("%d %d %d", &n, &f, &rr);
  for(int i = 1; i <= n; ++i) p[i] = i, r[i] = 0;
  for(int i = 0; i < f; ++i){
    scanf("%d %d %d", &a, &b, &c);
    edges.push_back(pip(c, pii(a, b)));
  }
  sort(edges.begin(), edges.end());
  for(int i = 0; i < edges.size(); ++i){
    if(find(edges[i].ss.ff) != find(edges[i].ss.ss)){
      join(edges[i].ss.ff, edges[i].ss.ss);
      ans += edges[i].ff;
    }
  }
  edges.clear();
  for(int i = 0; i < rr; ++i){
    scanf("%d %d %d", &a, &b, &c);
    edges.push_back(pip(c, pii(a, b)));
  }
  sort(edges.begin(), edges.end());
  for(int i = 0; i < edges.size(); ++i){
    if(find(edges[i].ss.ff) != find(edges[i].ss.ss)){
      join(edges[i].ss.ff, edges[i].ss.ss);
      ans += edges[i].ff;
    }
  }
  printf("%d\n", ans);
  return 0;
}
