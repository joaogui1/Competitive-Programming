#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <int, int> pii;

int main(){
  ios_base::sync_with_stdio(0);
  int n, x;
  string s;
  char trash;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> s;
    stringstream ss(s);
    for(int j = 0; j < 4; ++j)  ss >> trash;
    ss >> x;
    if(x == 9)  cout << 1989 << "\n";
    else if(x < 9)  cout << 199 << x << "\n";
    else if(x < 100)  cout << 20 << x << "\n";
    else if(x < 1000) cout << 2 << x << "\n";
  }



  return 0;
}
