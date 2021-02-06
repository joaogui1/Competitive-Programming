#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <int, int> pii;

int main(){
  ios_base::sync_with_stdio(0);
  int plus = 0, minus = 0, aux;
  string s;
  char op;
  getline(cin, s);
  for(int i = 0; i < s.size(); ++i){
    if(s[i] == '+') ++plus;
    else if(s[i] == '-')  ++minus;
  }
  stringstream ss(s);
  if(minus > plus) cout << "Impossible\n";
  else{
    cout << "Possible\n";
    while(ss >> op)
      if(op == '=')
        break;

    ss >> aux;
    cout << aux;
    for(int i = 1; s[i] != '='; ++i){
      if(s[i] == '?') cout << 1;
      else  cout << s[i];
    }
    cout << "= " << aux << "\n";
  }


  return 0;
}
