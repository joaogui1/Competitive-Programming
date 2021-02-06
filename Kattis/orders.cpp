#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pii;

int dp[31100];
vector <int> c;
vector <int> ans;
int main(){
  ios_base::sync_with_stdio(0);
  int n, aux;
  cin >> n;
  c.assign(n, 0);
  memset(dp, -1, sizeof dp);
  for(int i = 0; i < n; ++i)  cin >> c[i];
  dp[0] = 0;

  for(int j = 0; j < c.size(); ++j)
    for(int i = 0; i < 31100 - c[j]; ++i){
      if(dp[i] > -1 && dp[i + c[j]] == -1)  dp[i + c[j]] = j;
      else if(dp[i] > -1 && dp[i + c[j]] != -1) dp[i + c[j]] = -2;
      else if(dp[i] == -2)  dp[i + c[j]] = -2;
    }
  cin >> n;

  for(int i = 0; i < n; ++i){
    cin >> aux;
    ans.clear();

    if(dp[aux] == -1) cout << "Impossible\n";
    else if(dp[aux] == -2) cout << "Ambiguous\n";

    else{
      while(aux != 0){
        ans.push_back(dp[aux]);
        aux -= c[dp[aux]];
      }
      for(int i = (int)ans.size() - 1; i > -1; --i) cout << (ans[i] + 1) << " \n"[i == 0];
    }


  }


  return 0;
}
