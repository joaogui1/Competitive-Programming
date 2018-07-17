#include <bits/stdc++.h>

using namespace std;

string in, ans[2] = {"Not Palindrome", "Palindrome"};
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  bool vdc = 1;
  cin >> in;
  for(int i = 0; i < in.size(); ++i)
    if(in[i] >= 'A' && in[i] <= 'Z')  in[i] += ('a' - 'A'); 
  for(int i = 0; i < in.size()/2; ++i)
    if(in[i] != in[in.size() - i - 1]){
      vdc = 0;
      break;
    }
  cout << ans[vdc] << "\n";
  return 0;
}
