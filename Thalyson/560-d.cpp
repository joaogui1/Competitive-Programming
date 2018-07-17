#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

string ans[2] = {"NO", "YES"};

string lex_min(string a){
  if((a.size())&1)  return a;
  string b, c;
  b = lex_min(a.substr(0, a.size()/2));
  c = lex_min(a.substr(a.size()/2, a.size()/2));
  if(b < c) return b + c;
  else  return c + b;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string a, b;
  cin >> a >> b;
  cout << ans[lex_min(a) == lex_min(b)] << "\n";

  return 0;
}
