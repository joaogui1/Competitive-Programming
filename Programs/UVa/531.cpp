#include <bits/stdc++.h>

using namespace std;

int dp[110][110], sz[3], mans;
string text[2][110];
vector <string> ans;

int f(int i, int j){
    if(i < 0 || j < 0)  return 0;
    if(dp[i][j] != -1)  return dp[i][j];
    if(text[0][i] == text[1][j])  return dp[i][j] = f(i - 1, j - 1) + 1;

    return dp[i][j] = max(f(i - 1, j), f(i, j - 1));
}

void initialize(){
  mans = -1;
  sz[0] = sz[1] = 0;
  ans.clear();
  for(int i = 0; i < 2; ++i)
    for(int j = 0; j < 110; ++j)
      text[i][j] = "";
  memset(dp, -1, sizeof dp);
}

int main(){
  ios_base::sync_with_stdio(0);
  string input;
  while(cin >> input){
    initialize();
    for(int i = 0; i < 2; ++i){
      while(input != "#"){
        text[i][sz[i]] = input;
        ++sz[i];
        cin >> input;
      }
      if(i == 0)  cin >> input;
    }
    f(sz[0] - 1, sz[1] - 1);

    for(int i = 0; i < sz[0]; ++i)
      for(int j = 0; j < sz[1]; ++j)
        mans = max(mans, dp[i][j]);

    for(int i = sz[0] - 1; i > -1 && mans; --i)
      for(int j = sz[1] - 1; j > -1; --j)
        if(text[0][i] == text[1][j] && dp[i][j] == mans){
          --mans;
          ans.push_back(text[0][i]);
          break;
        }

    for(int i = ans.size() - 1; i > 0; --i)  cout << ans[i] << " ";
    cout << ans[0] << "\n"; 
  }


  return 0;
}
