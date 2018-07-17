#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

bool ready(string s){
  for(int i = 0; i < s.size(); ++i)
    if(s[i] == '-') return 0;
  return 1;
}

string invert(int pos, string x){
  for(int i = 0; i <= pos/2; ++i){
    x[i] = (x[i] == '-')?'+':'-';
    if(2*i != pos){
      x[pos - i] = (x[pos - i] == '-')?'+':'-';
      swap(x[i], x[pos - i]);
    }
  }

  return x;
}

ll f(string x){
  ll ret = 0, pos;
  while(!ready(x)){
    pos = 0;
    for(int i = 1; i < x.size() && x[i] == x[i - 1]; ++i) pos = i;
    ++ret;
    x = invert(pos, x);
  }
  return ret;
}


int main(){
  ios_base::sync_with_stdio(0);
  int t;
  string s;
  cin >> t;
  for(int i = 1; i <= t; ++i){
    cin >> s;
    cout << "Case #" << i << ": " << f(s) << "\n";
  }

  return 0;
}
