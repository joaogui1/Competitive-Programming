#include <bits/stdc++.h>

using namespace std;

map <char, int> m;

void pre(){
  m['A'] = m['B'] = m['C'] = 2;
  m['D'] = m['E'] = m['F'] = 3;
  m['G'] = m['H'] = m['I'] = 4;
  m['J'] = m['K'] = m['L'] = 5;
  m['M'] = m['N'] = m['O'] = 6;
  m['P'] = m['Q'] = m['R'] = m['S'] = 7;
  m['T'] = m['U'] = m['V'] = 8;
  m['W'] = m['X'] = m['Y'] = m['Z'] = 9;
  return;
}

int main(){
  pre();
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); ++i){
    if(s[i] == '-' || ('1' <= s[i] && s[i] <= '9')) cout << s[i];
    else{
      cout << m[s[i]];
    }
  }
  cout << "\n";


  return 0;
}
