#include <bits/stdc++.h>
#define left(x) get<0>(x)
#define right(x) get<1>(x)
#define sum(x)  get<2>(x)
#define lval(x) get<3>(x)
#define rval(x) get<4>(x)
#define lpos(x) get<5>(x)
#define rpos(x) get<6>(x)

using namespace std;
typedef long long int ll;
//typedef tuple <ll, ll, ll, ll, ll, ll, ll> tll;
ll v[100010];
//tll seg[800080];

class data{
  public:
    ll ans, lis, ris, lval, rval, lpos, rpos;
};
data seg[400040];

data join(data left, data right){
  data ret;
  ret.ans = max(left.ans, right.ans);
  if(left.rval < right.lval)  ret.ans = max(ret.ans, left.ris + right.lis);

  ret.lval = left.lval;
  ret.rval = right.rval;
  ret.lpos = left.lpos;
  ret.rpos = right.rpos;
  ret.lis = left.lis;
  ret.ris = right.ris;

  if(left.ans == (left.rpos - left.lpos + 1) && left.rval < right.lval)
    ret.lis += right.lis;

  if(right.ans == (right.rpos - right.lpos + 1) && left.rval < right.lval)
    ret.ris += left.ris;
  return ret;

}

data make(int val, int b){
  data ret;
  ret.ans = ret.lis = ret.ris = 1;
  ret.lval = ret.rval = val;
  ret.lpos = ret.rpos = b;
  return ret;
}

void make_seg(int node, int l, int r){
  if(l == r){
    seg[node] = make(v[l], l);
    //cout << node << " " << seg[node].ans << endl;
    return;
  }
  int mid = (l + r) >> 1;
  make_seg(2*node, l, mid);
  make_seg(2*node + 1, mid + 1, r);
  seg[node] = join(seg[2*node], seg[2*node + 1]);
  //cout << node << " " << seg[node].ans << endl;
  return;
}

data query(int node, int l, int r, int a, int b){
  if(a <= l && r <= b)  return seg[node];

  int mid = (l + r) >> 1;

  if(b <= mid)  return query(2*node, l, mid, a, b);
  if(a > mid) return query(2*node + 1, mid + 1, r, a, b);

  data L, R;
  L = query(2*node, l, mid, a, b);
  R = query(2*node + 1, mid + 1, r, a, b);

  return join(L, R);
}

void update(int node, int l, int r, int idx, ll val){
  if(l == r){
    seg[node].rval += val;
    seg[node].lval += val;
    return;
  }


  int mid = (l + r) >> 1;

  if(idx <= mid)  update(2*node, l, mid, idx, val);
  else  update(2*node + 1, mid + 1, r, idx, val);

  seg[node] = join(seg[2*node], seg[2*node + 1]);
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, q, op;
  ll p, x, y;
  cin >> t;
  while(t--){
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
      cin >> v[i];
    make_seg(1, 1, n);
    //for(int i = 1; i < 10; ++i) cout << seg[i].ans << endl;

    for(int i = 0; i < q; ++i){
      cin >> op >> x >> y;
      if(op == 0) cout << query(1, 1, n, x, y).ans << "\n";
      else  update(1, 1, n, x, y);
    }
  }


  return 0;
}
