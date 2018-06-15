#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string in;
  cin >> in;
  int a = 0, b = 0;
  for(int i = 0; i < in.size(); ++i){
    if(in[i] == 'C')  a = 1;
    if(in[i] == 'F')  b += a;
  }

  if(a*b > 0) cout << "Yes\n";
  else  cout << "No\n";


  return 0;
}
