#include <bits/stdc++.h>

using namespace std;

string in[1024];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  bool vdc = 0;
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> in[i];
  for(int i = 0; i < n; ++i){
    if(in[i][0] == in[i][1] && in[i][0] == 'O'){
      in[i][0] = in[i][1] = '+';
      vdc = 1;
      break;
    }
    if(in[i][3] == in[i][4] && in[i][3] == 'O'){
      in[i][3] = in[i][4] = '+';
      vdc = 1;
      break;
    }
  }
  if(vdc){
    cout << "YES\n";
    for(int i = 0; i < n; ++i)
      cout << in[i] << "\n";
  }
  else  cout << "NO\n";

  return 0;
}
