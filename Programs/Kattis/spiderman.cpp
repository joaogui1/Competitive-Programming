#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <int, string> pis;

vector <int> heights;
pis dp[50][(1 << 10)];

pis f(int idx, int h){
  if(dp[idx][h].ff != -1)  return dp[idx][h];
  if(idx == heights.size()) return dp[idx][h] = (h == 0)?(pis(0, "")):(pis(1 << 20, ""));
  pis ret;


  ret = pis(f(idx + 1, h + heights[idx]).ff, "U" + f(idx + 1, h + heights[idx]).ss);
  if(h - heights[idx] > -1 && f(idx + 1, h - heights[idx]).ff < ret.ff)
    ret = pis(f(idx + 1, h - heights[idx]).ff, "D" + f(idx + 1, h - heights[idx]).ss);
  ret.ff = max(ret.ff, h);
  return dp[idx][h] = ret;
}

void initialize(){
  heights.clear();
  for(int i = 0; i < 50; ++i)
    for(int j = 0; j < (1 << 10); ++j)
      dp[i][j].ff = -1;
  return;
}

int main(){
  ios_base::sync_with_stdio();
  int n, h, m;
  cin >> n;
  while(n--){
    cin >> m;
    initialize();
    while(m--){
      cin >> h;
      heights.push_back(h);
    }
    cout << ((f(0,0).ff != (1 << 20))?f(0, 0).ss:("IMPOSSIBLE")) << "\n";
  }

  return 0;
}
