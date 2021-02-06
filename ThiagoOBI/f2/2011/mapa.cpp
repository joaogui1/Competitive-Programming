#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

int p[512];
vector <pip> ed;

int find(int x){
  return (x == p[x])?x:(p[x] = find(p[x]));
}

void join(int x, int y){
  p[find(x)] = find(y);
}

int main(){
  int n, m, u, v, w, ans = 0;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i) p[i] = i;
  for(int i = 0; i < m; ++i){
    scanf("%d %d %d", &u, &v, &w);
    ed.push_back(pip(w, pii(u, v)));
  }
  sort(ed.begin(), ed.end());
  for(int i = 0; i < ed.size(); ++i){
    if(find(ed[i].ss.ff) != find(ed[i].ss.ss)){
      ans += ed[i].ff;
      join(ed[i].ss.ff, ed[i].ss.ss);
    }
  }

  printf("%d\n", ans);
  return 0;
}
