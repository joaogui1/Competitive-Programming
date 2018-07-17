#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <int, int> pii;

pii x[1024], y[1024];
int cost[1024][1024], dist[1024], mark[1024];

int main(){
  pii aup;
  int n, xi, xf, yi, yf, d;
  scanf("%d %d %d %d %d", &xi, &yi, &xf, &yf, &n);
  x[n] = pii(xi, xi), y[n] = pii(yi, yi);
  x[n + 1] = pii(xf, xf), y[n + 1] = pii(yf, yf);
  for(int i = 0; i < n; ++i)
    scanf("%d %d %d %d", &x[i].ff, &y[i].ff, &x[i].ss, &y[i].ss);
  memset(cost, 0x3f3f3f3f, sizeof cost);
  for(int i = 0; i <= n + 1; ++i)
    for(int j = 0; j <= n + 1; ++j)
      cost[i][j] = max(0, max(x[i].ff, x[j].ff) - min(x[i].ss, x[j].ss)) + max(0, max(y[i].ff, y[j].ff) - min(y[i].ss, y[j].ss));
  memset(dist, 0x3f3f3f3f, sizeof dist);
  dist[n] = 0;
  priority_queue <pii, vector<pii>, greater<pii> > pq;
  pq.push(pii(dist[n], n));
  while(pq.size()){
    while(pq.size()){
      aup = pq.top(); pq.pop();
      if(aup.ff != dist[aup.ss])  continue;
      break;
    }
    if(aup.ff != dist[aup.ss])  break;
    mark[aup.ss] = 1;
    for(int i = 0; i <= n + 1; ++i){
      if(mark[i]) continue;
      d = aup.ff + cost[aup.ss][i];
      if(d < dist[i]){
        dist[i] = d;
        pq.push(pii(d, i));
      }
    }
  }

  printf("%d\n", dist[n + 1]);

  return 0;
}
