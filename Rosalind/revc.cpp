#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string in;
  cin >> in;
  for(int i = in.size() - 1; i > -1; --i){
    if(in[i] == 'A')  cout << 'T';
    if(in[i] == 'T')  cout << 'A';
    if(in[i] == 'C')  cout << 'G';
    if(in[i] == 'G')  cout << 'C';
  }
  cout << "\n";




  return 0;
}
