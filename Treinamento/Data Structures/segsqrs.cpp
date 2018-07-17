#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll seg[400010], lazy[2][400010];

ll query(int node, int l, int r, int a, int b){
  if(l > b || a > r)  return 0;
  if(lazy[0][node] > -1001){
    seg[node] += lazy[0][node];

  }
  if(a <= l && b <= r)  return seg[node];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, T, q;
  cin >> T;
  for(int t = 1; t <= T; ++t){
    cout << "Case " << t << ":\n";
    memset(seg, 0, sizeof seg);
    memset(lazy, 0, sizeof lazy);

    cin >> n >> q;

  }



  return 0;
}
