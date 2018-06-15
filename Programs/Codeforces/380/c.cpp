#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;

int n, m;
string seq;
int v[1000100];
ppi seg[8000800];

ppi add(ppi a, ppi b){
  ppi res;
  int t = min(a.ss.ff, b.ss.ss);
  res.ff = a.ff + b.ff + 2*t;
  res.ss.ff = a.ss.ff + b.ss.ff - t;
  res.ss.ss = a.ss.ss + b.ss.ss - t;
  return res;
}

void build_seg(int node, int a, int b){
  if(a == b){
    seg[node].ff = 0;
    seg[node].ss.ff = (v[a] == 1);
    seg[node].ss.ss = (v[a] == -1);
    return;
  }
  int m = (a + b)/2;
  build_seg(2*node, a, m);
  build_seg(2*node + 1, m + 1, b);
  seg[node] = add(seg[2*node], seg[2*node + 1]);
  // t = min(seg[2*node].ss.ff, seg[2*node + 1].ss.ss);
  // seg[node].ff = seg[2*node].ff + seg[2*node + 1].ff + 2*t;
  // seg[node].ss.ff = seg[2*node].ss.ff + seg[2*node + 1].ss.ff - t;
  // seg[node].ss.ss = seg[2*node].ss.ss + seg[2*node + 1].ss.ss - t;
  return;
}

ppi query(int node, int a, int b, int x, int y){
  if(a > y || b < x)  return ppi(0, pii(0,0));
  if(x <= a && b <= y)  return seg[node];
  ppi q1, q2, res;
  int m = (a + b)/2, t;
  q1 = query(2*node, a, m, x, y);
  q2 = query(2*node + 1, m + 1, b, x, y);
  res = add(q1, q2);
  return res;
}


int main(){
  int a, b;
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> seq >> m;
  n = seq.size();

  for(int i = 0; i < n; ++i){
    if(seq[i] == '(') v[i + 1] = 1;
    else if(seq[i] == ')')  v[i + 1] = -1;
  }
  build_seg(1, 1, n);
  for(int i = 0; i < m; ++i){
    cin >> a >> b;
    cout << (query(1, 1, n, a, b).ff) << "\n";
  }



  return 0;
}
