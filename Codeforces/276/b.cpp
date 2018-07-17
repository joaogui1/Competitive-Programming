#include <bits/stdc++.h>

using namespace std;

string in;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int mask = 0, ans = 0;
  cin >> in;
  for(int i = 0; i < in.size(); ++i)  mask ^= (1 << (in[i] - 'a'));
  for(int i = 0; i < 26; ++i) ans += ((mask&(1 << i)) > 0);
  if(ans == 0)  cout << "First\n";
  else if(ans%2 == 0) cout << "Second\n";
  else  cout << "First\n";
  
  return 0;
}
