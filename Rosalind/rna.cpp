#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string in;
  cin >> in;
  for(int i = 0; i < in.size(); ++i){
    if(in[i] == 'T')  in[i] = 'U';
    cout << in[i];
  }
  cout << "\n";




  return 0;
}
