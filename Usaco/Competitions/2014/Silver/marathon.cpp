#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

int dp[512][512];
vector <pii> point;

int dist(pii a, pii b){
  return abs(a.ff - b.ff) + abs(a.ss - b.ss);
}

int f(int n, int k){
  if(n == point.size() - 1) return 0;
  if(n >= point.size()) return (1 << 27);
  if(dp[n][k] != -1)  return dp[n][k];
  dp[n][k] = (1 << 27);
  for(int i = 0; i <= k; ++i){
    if(i + n >= point.size()) break;
    else  dp[n][k] = min(dp[n][k], f(n + i + 1, k - i) + dist(point[n], point[n + i + 1]));
  }
  return dp[n][k];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ifstream fin ("marathon.in");
  ofstream fout ("marathon.out");
  int n, k, a, b;
  fin >> n >> k;
  memset(dp, -1, sizeof dp);
  for(int i = 0; i < n; ++i){
    fin >> a >> b;
    point.push_back(pii(a, b));
  }
  fout << f(0, k) << "\n";

  return 0;
}
