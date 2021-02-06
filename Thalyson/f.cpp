#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int x = 0, y = 0;
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); ++i){
    if(s[i] == 'x') ++x;
    else  ++y;
  }
  if(x > y){
    for(int i = y; i < x; ++i)  cout << "x";
    cout << "\n";
  }
  else{
    for(int i = x; i < y; ++i)  cout << "y";
    cout << "\n";
  }

  return 0;
}
