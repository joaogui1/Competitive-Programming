#include <bits/stdc++.h>

using namespace std;

int seg[800800], lazy[800800];
string input;

int query(int node, int l, int r, int a, int b){
  if(a > r || l > b)  return 0;

  if(lazy[node] != 0){
    if(lazy[node] % 2 == 1)  seg[node] = (r - l + 1) - seg[node];
    if(l != r){
      lazy[2*node] += lazy[node];
      lazy[2*node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }

  if(a <= l && r <= b)  return seg[node];

  int mid = (l + r) >> 1;
  return query(2*node, l, mid, a, b) + query(2*node + 1, mid + 1, r, a, b);
}

void update(int node, int l, int r, int a, int b){
  if(lazy[node] != 0){
    if(lazy[node] % 2 == 1)  seg[node] = (r - l + 1) - seg[node];
    if(l != r){
      lazy[2*node] += lazy[node];
      lazy[2*node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(a > r || l > b)  return;
  //cout << node << " " << l << " " << r << endl;

  //if(node == 6) cout << l << " " << r << " " << a << " " << b << endl << endl << endl;
  if(a <= l && r <= b){
    seg[node] = (r - l + 1) - seg[node];
    if(l != r){
      ++lazy[2*node];
      ++lazy[2*node + 1];
    }
    return;
  }

  int mid = (l + r) >> 1;
  update(2*node, l, mid, a, b);
  update(2*node + 1, mid + 1, r, a, b);
  seg[node] = seg[2*node] + seg[2*node + 1];
  return;
}

void make_tree(int node, int l, int r){
  if(l == r){
    if(input[l - 1] == '<') seg[node] = 1;
    return;
  }

  int mid = (l + r) >> 1;
  make_tree(2*node, l, mid);
  make_tree(2*node + 1, mid + 1, r);
  seg[node] = seg[2*node] + seg[2*node + 1];
  return;
}

void debug(int node, int l, int r){
  if(l == r){
    cout << node << " " << seg[node] << endl;
    return;
  }

  int mid = (l + r) >> 1;
  debug(2*node, l, mid);
  debug(2*node + 1, mid + 1, r);
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, m, l, r, op;
  cin >> n >> m;
  cin >> input;
  --n;
  make_tree(1, 1, n);
  //for(int i = 1; i <= 9; ++i) cout << i << " " <<  seg[i] << "\n";
  while(m--){
    cin >> op >> l >> r;
    if(op == 1) {
      update(1, 1, n, l, r - 1);
      //for(int i = 1; i <= 9; ++i) cout << i << " " <<  seg[i] << " " << lazy[i] << "\n";
    }
    else{
      if(l < r) cout << query(1, 1, n, l, r - 1) << "\n";
      else if(l > r)  cout << (l - r) - query(1, 1, n, r, l - 1) << "\n";
      else  cout << "0\n";
      //for(int i = 1; i <= 9; ++i) cout << i << " " <<  seg[i] << " " << lazy[i] << "\n";
    }
    //cout << endl;
  }
  return 0;
}
