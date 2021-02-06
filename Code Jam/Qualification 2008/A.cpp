#include <bits/stdc++.h>

using namespace std;

int dp[1 << 10][1 << 7];
vector <string> sear;
vector <string> queries;

int f(int x, int se){
  if(x >= queries.size())  return 0;
  if(dp[x][se] != -1) return dp[x][se];
  dp[x][se] = (1 << 20);
  if(queries[x] == sear[se]){
    for(int i = 0; i < sear.size(); ++i)
      if(i != se)
        dp[x][se] = min(dp[x][se], 1 + f(x + 1, i));
  }
  else  return dp[x][se] = f(x + 1, se);
  return dp[x][se];
}

int f(){
  int ret = (1 << 20);
  for(int i = 0; i < sear.size(); ++i)
    ret = min(ret, f(0, i));
  return ret;
}

void initialize(){
  for(int i = 0; i < (1 << 10); ++i)
    for(int j = 0; j < (1 << 7); ++j)
      dp[i][j] = -1;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, s, q;
  string trash;
  cin >> n;
  for(int t = 1; t <= n; ++t){
    initialize();

    cin >> s;
    sear.assign(s, "");
    getline(cin, trash);
    for(int i = 0; i < s; ++i)
      getline(cin,sear[i]);

    cin >> q;
    queries.assign(q, "");
    getline(cin, trash);
    for(int i = 0; i < q; ++i)
      getline(cin, queries[i]);

    cout << "Case #" << t << ": " << f() << "\n";

  }


  return 0;
}
