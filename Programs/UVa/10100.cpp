#include <bits/stdc++.h>

using namespace std;

int sz[5], beg, dp[1010][1010];
string input[5], text[5][1100];

void initialize(){
  memset(dp, -1, sizeof dp);
  memset(sz, 0, sizeof sz);
  //for(int i = 0; i < 5; ++i)  input[i] = "";
  for(int i = 0; i < 5; ++i)
    for(int j = 0; j < 1100; ++j) text[i][j] = "";
  return;
}

int f(int i, int j){
  if(i < 0 || j < 0)  return 0;
  if(dp[i][j] != -1)  return dp[i][j];
  if(text[0][i] == text[1][j])  return dp[i][j] = 1 + f(i - 1, j - 1);
  return dp[i][j] = max(f(i - 1, j), f(i, j - 1));
}

int main(){
  int count = 0;
  string aus;
  ios_base::sync_with_stdio(0);
  while(getline(cin, input[0])){
    getline(cin, input[1]);
    initialize();
    ++count;
    cout << setw(2) << setiosflags(ios::right) << count <<". ";
    if(input[0].size() > 0 && input[1].size() > 0){
      for(int j = 0; j < 2; ++j)
        for(int i = 0; i < input[j].size(); ++i)
          if(!isupper(input[j][i]) && !islower(input[j][i]) && !isdigit(input[j][i])) input[j][i]=' ';

       istringstream in0(input[0]);
       istringstream in1(input[1]);

      while(in0 >> aus){
        text[0][sz[0]] = aus;
        ++sz[0];
      }

      while(in1 >> aus){
        text[1][sz[1]] = aus;
        ++sz[1];
      }
      //cout << sz[0] << " " << sz[1] << endl;

      cout << "Length of longest match: " << f(sz[0] - 1, sz[1] - 1) << "\n";
    }
    else  cout << "Blank!\n";
  }



  return 0;
}
