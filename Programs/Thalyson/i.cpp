#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  string s;
  cin >> s;
  n = s.size() - 1;
  for(int i = 0; i < s.size(); ++i)
    if(s[i] == '0'){
      n = i;
      break;
    }
  for(int i = 0; i < s.size(); ++i){
    if(i != n)  cout << s[i];
  }
  cout << "\n";

  return 0;
}
