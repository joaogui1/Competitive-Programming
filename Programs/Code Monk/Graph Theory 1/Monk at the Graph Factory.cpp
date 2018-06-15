#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int n, tot = 0, aux;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> aux;
    tot += aux;
  }
  if(tot/2 == n -1) cout << "Yes\n";
  else  cout << "No\n";

  return 0;
}
