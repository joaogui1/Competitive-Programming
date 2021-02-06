#include <bits/stdc++.h>

using namespace std;
vector <int> fr;
vector <char> ss;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string s, ss;
  while(getline(cin, s))  ss += s;
  int f = 1, pop = 0;
  unsigned long long int a = 0, cont, hp, gpg = 1LL;
  cout << "{";
  for(int i = 0; i < ss.size(); ++i){
    cont = i%64;
    if(cont == 0 && a != 0){
      cout << a << "LL, ";
      a = 0;
    }
    if(ss[i] != '0' && ss[i] != '1'){
      cout << ss[i] << "\n";
      continue;
    }
    hp = (ss[i] != '0');
    a |= (hp*(gpg << cont));
  }
  cout << a << "LL";
  cout << "}";
  // while(getline(cin, s)){
  //   for(int i = 0; i < s.size(); ++i)
  //     if(i == 0 || s[i] != s[i - 1])
  //       ss.push_back(s[i]);
  //   for(int i = 1; i < s.size(); ++i){
  //     if(s[i] != s[i - 1]){
  //       fr.push_back(f);
  //       f = 1;
  //     }
  //     else ++f;
  //   }
  //   fr.push_back(f);
  //   cout << "{";
  //   for(int i = 0; i < ss.size(); ++i)
  //     cout << "\'" << ss[i] << "\' , ";
  //   cout << "}";
  //   cout << "{";
  //   for(int i = 0; i < fr.size(); ++i)
  //     cout << fr[i] << ", ";
  //   cout << "}";
  // }
  return 0;
}
