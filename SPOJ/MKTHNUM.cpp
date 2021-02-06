#include <bits/stdc++.h>

using namespace std;

int vec[131072];
vector<int> seg[524288];

void make_tree(int node, int l, int r){
  if(l == r){
      seg[node].push_back(vec[l]);
      return;
  }
  int i = 0, j = 0, m = (l + r) >> 1;
  make_tree(2*node, l, m);
  make_tree(2*node + 1, m + 1, r);
  while(i < seg[2*node].size() && j < seg[2*node + 1].size()){
    if(seg[2*node][i] < seg[2*node + 1][j]) seg[node].push_back(seg[2*node][i]), ++i;
    else  seg[node].push_back(seg[2*node + 1][j]), ++j;
  }
  for(; i < seg[2*node].size(); ++i)  seg[node].push_back(seg[2*node][i]);
  for(; j < seg[2*node + 1].size(); ++j)  seg[node].push_back(seg[2*node + 1][j]);
  return;
}

int query(int node, int l, int r, int a, int b, int val){
  if(l > r) return 0;
  if(b < l || a > r)  return 0;
  if(a <= l && r <= b)  return (upper_bound(seg[node].begin(), seg[node].end(), val) - seg[node].begin());
  int m = (l + r) >> 1;
  return query(2*node, l, m, a, b, val) + query(2*node + 1, m + 1, r, a, b, val);
}

int bin_search(int n, int a, int b, int c){
  int lo = -(1000000000), hi = 1000000000, mid;
  while(hi > lo){
    //cout << hi << " " << lo << " " << query(1, 1, n, a, b, mid) << "\n";
    mid = lo + ((hi - lo) >> 1);
    if(query(1, 1, n, a, b, mid) < c) lo = mid + 1;
    else  hi = mid;
  }
  return lo;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, q, a, b, c;
  cin >> n >> q;
  for(int i = 1; i <= n; ++i) cin >> vec[i];
  make_tree(1, 1, n);
  for(int i = 0; i < q; ++i){
    cin >> a >> b >> c;
    cout << bin_search(n, a, b, c) << "\n";
  }



  return 0;
}
