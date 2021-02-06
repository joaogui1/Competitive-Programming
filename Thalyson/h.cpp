#include <bits/stdc++.h>

using namespace std;

int sq[4][4];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int sum = 0, val;
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j){
      cin >> sq[i][j];
      sum += sq[i][j];
    }
  sum /= 2;
  for(int i = 0; i < 3; ++i){
    val = 0;
    for(int j = 0; j < 3; ++j)  val += sq[i][j];
    val = sum - val;
    for(int j = 0; j < 3; ++j){
      if(i == j)  cout << val;
      else  cout << sq[i][j];
      cout << " \n"[j == 2];
    }
  }


  return 0;
}
