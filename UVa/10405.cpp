#include <bits/stdc++.h>

using namespace std;

int dp[1100][1100];
string text[5];

void initialize(){
  memset(dp, -1, sizeof dp);
  return;
}

int f(int i, int j){
  if(i < 0 || j < 0)  return 0;
  if(dp[i][j] != -1)  return dp[i][j];
  if(text[0][i] == text[1][j])  return dp[i][j] = 1 + f(i - 1, j - 1);
  return dp[i][j] = max(f(i - 1, j), f(i, j - 1));
}

int main(){
  ios_base::sync_with_stdio(0);
  while(getline(cin, text[0])){
    initialize();
    getline(cin, text[1]);
    cout << f(text[0].size() - 1, text[1].size() - 1) << "\n";
  }



  return 0;
}
