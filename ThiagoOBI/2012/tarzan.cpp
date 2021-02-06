#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair <ll, ll> pll;

int n, mark[1024];
pll c[1024];
vector <int> adj[1024];

bool dfs(int x){
  mark[x] = 1;
  bool ret = 1;
  for(int i = 0; i < adj[x].size(); ++i)
    if(!mark[adj[x][i]])
      dfs(adj[x][i]);
  if(x == 0)
    for(int i = 0; i < n; ++i)
      ret &= mark[i];
  return ret;
}

int main(){
  ll d, x, y;
  scanf("%d %lld", &n, &d);
  for(int i = 0; i < n; ++i){
    scanf("%lld %lld", &c[i].ff, &c[i].ss);
    for(int j = 0; j < i; ++j)
      if((c[i].ff - c[j].ff)*(c[i].ff - c[j].ff) + (c[i].ss - c[j].ss)*(c[i].ss - c[j].ss) <= d*d){
        adj[j].push_back(i);
        adj[i].push_back(j);
      }
  }
  printf("%s\n", (dfs(0))?"S":"N");

  return 0;
}
