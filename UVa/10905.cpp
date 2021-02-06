#include <bits/stdc++.h>

using namespace std;

string v[64];

bool comp(string a, string b){
  return (a + b) > (b + a);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  while(1){
    cin >> n;
    if(n == 0)  return 0;
    for(int i = 0; i < n; ++i)  cin >> v[i];
    sort(v, v + n, comp);
    for(int i = 0; i < n; ++i) cout << v[i];
    cout << "\n";
  }



  return 0;
}
