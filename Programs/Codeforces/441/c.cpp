#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair <int, int> pii;

queue <pii> res;
void pre(int n, int m){
  for(int i = 1; i <= n; ++i)
    for(int j = ((i + 1)&1)*(m - 1) + 1; j != 0 && j != m + 1; j += (2*(i&1) - 1))
      res.push(pii(i, j));
}

void ans(int k){
  if(k != 1){
    cout << 2 << " ";
    for(int i = 0; i < 2; ++i){
      cout << res.front().ff << " " << res.front().ss << " ";
      res.pop();
    }
    cout << "\n";
    ans(k - 1);
  }
  else{
    cout << res.size() << " ";
    while(res.size()){
      cout << res.front().ff << " " << res.front().ss << " ";
      res.pop();
    }
    cout << "\n";
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  pre(n, m);
  // while(res.size()){
  //   cout << res.front().ff << " " << res.front().ss << "\n";
  //   res.pop();
  // }
  ans(k);
  return 0;
}
