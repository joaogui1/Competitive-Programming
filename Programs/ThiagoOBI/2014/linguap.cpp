#include <bits/stdc++.h>

using namespace std;

int main(){
  bool rm = 1;
  string s;
  getline(cin, s);
  for(int i = 0; i < s.size(); ++i){
    if(s[i] == 'p' && rm){
      rm = 0;
      continue;
    }
    rm = 1;
    printf("%c", s[i]);
  }
  printf("\n");

  return 0;
}
