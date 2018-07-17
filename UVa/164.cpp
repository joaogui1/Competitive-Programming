#include <bits/stdc++.h>

using namespace std;

string input, output, ans;
int dp[1 << 10][1 << 10];

int f(int i, int j){
  int cost = 0;
  //cout << i << " " << j << endl;
  if(dp[i][j] != -1)  return dp[i][j];
  if(i == input.size() || j == output.size()) return (input.size() + output.size() - i - j);
  cost = ((input[i] == output[j])?(0):(1));
  return dp[i][j] = min(1 + min(f(i + 1, j), f(i, j + 1)), cost + f(i + 1, j + 1));
}

void initialize(){
  ans.clear();
  memset(dp, -1, sizeof dp);
  return;
}

void print(int i, int j){
  if(i == input.size() || j == output.size())  return;

  if(dp[i][j] == dp[i + 1][j + 1]){
    print(i + 1, j + 1);
    return;
  }

  if(dp[i][j] == dp[i + 1][j + 1] + 1){
    cout << "C" << output[j];
    print(i + 1, j + 1);
    return;
  }

  if(dp[i][j] == dp[i + 1][j] + 1){
    cout << "D" << input[i];
    print(i + 1, j);
    return;
  }

  if(dp[i][j] == dp[i][j + 1] + 1){
    cout << "I" << output[j];
    print(i, j + 1);
    return;
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  while(1){
    cin >> input;
    if(input == "#")  return 0;
    cin >> output;
    initialize();
    cout << f(0, 0) << "\n";
    cout << ans << endl;
  }



  return 0;
}
