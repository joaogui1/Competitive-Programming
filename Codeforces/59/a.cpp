#include <bits/stdc++.h>

using namespace std;

string in;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int l = 0, u = 0;
  cin >> in;
  for(int i = 0; i < in.size(); ++i){
    if(in[i] >= 'a' && in[i] <= 'z')  ++l;
    else  ++u;
  }
  if(l < u){
    for(int i = 0; i < in.size(); ++i){
      if(in[i] >= 'a' && in[i] <= 'z')  in[i] += ('A' - 'a');
      cout << in[i];
    }
    cout << "\n";
  }
  else{
    for(int i = 0; i < in.size(); ++i){
      if(in[i] >= 'A' && in[i] <= 'Z') in[i] += ('a' - 'A');
      cout << in[i];
    }
    cout << "\n";
  }


  return 0;
}
