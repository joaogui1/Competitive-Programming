#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

vector <pii> p;
int dp[256][256], n;

bool ccw(pii a, pii b){
  return (a.ff*b.ss - a.ss*b.ff >= 0);
}

bool ccw(pii a, pii b, pii c){
  return ccw(pii(b.ff - a.ff, b.ss - a.ss), pii(c.ff - a.ff, c.ss - a.ss));
}

bool comp(pii a, pii b){
  return (a.ss*b.ff <= b.ss*a.ff);
}

int f(int i, int j){
  if(dp[i][j] != -1)  return dp[i][j];
  if(j == n)  return 0;
  dp[i][j] = 0;
  for(int k = j + 1; k <= n; ++k)
    if(ccw(p[i], p[j], p[k]))
      dp[i][j] = max(dp[i][j], 1 + f(j, k));
  return dp[i][j];
}

int f(int i){
  int ret = 0;
  for(int j = i + 1; j <= n; ++j)
    ret = max(ret, f(i, j));
  return ret;
}

void initialize(){
  p.clear();
  p.push_back(pii(0, 0));
  memset(dp, -1, sizeof dp);
}

int main(){
  int x, y;
  for(int t = 1; scanf("%d", &n); ++t){
    initialize();
    if(n == 0)  break;
    for(int i = 0; i < n; ++i){
      scanf("%d %d", &x, &y);
      p.push_back(pii(x, y));
    }
    sort(++p.begin(), p.end(), comp);
    printf("Teste %d\n%d\n\n", t, 2 + f(0));
  }


  return 0;
}
