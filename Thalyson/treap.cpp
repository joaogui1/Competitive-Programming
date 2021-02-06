#include <bits/stdc++.h>
#define INF 2000000010

using namespace std;

struct node{
  int v, p, small, big, cnt, ans;
  node *l, *r;
  node(){}
  node(int _v, int _p){
    v = _v;
    p = _p;
    cnt = 1;
    l = r = NULL;
    big = small = v;
  }
};

void print(node *t){
  if(t == NULL) return;
  print(t -> l);
  cout << t -> v << " ";
  print(t -> r);
}

void upd(node *n){
  if(n == NULL) return;

  n -> ans = INF;
  n -> cnt = 1;
  n -> big = n -> small = n -> v;

  if(n -> l != NULL){
    n -> cnt += (n -> l -> cnt);
    n -> small = (n -> l -> small);

    n -> ans = min(n -> ans, (n -> l -> ans));
    n -> ans = min(n -> ans, (n -> v) - (n -> l -> big));
  }

  if(n -> r != NULL){
    n -> big = (n -> r -> big);
    n -> cnt += (n -> r -> cnt);

    n -> ans = min(n -> ans, (n -> r -> ans));
    n -> ans = min(n -> ans, (n -> r -> small) - (n -> v));
  }
}

void split(node *t, int val, node *&l, node *&r){
  if(t == NULL){
    l = r = NULL;
    return;
  }
  if(t -> v <= val){
    split(t -> r, val , t -> r, r);
    l = t;
  }
  else{
    split(t -> l, val, l, t -> l);
    r = t;
  }
  upd(t);
}

void merge(node *&t, node *l, node *r){
  if(l == NULL || r == NULL){
    if(l == NULL) t = r;
    else t = l;
  }
  else if(l -> p > r -> p){
    merge(l -> r, l -> r, r);
    t = l;
  }
  else{
    merge(r -> l, l, r -> l);
    t = r;
  }
  upd(t);
}

bool has(node *t, int k){
  if(t == NULL) return 0;
  if(t -> v == k) return 1;
  if(t -> v < k)  return has(t -> r, k);
  return has(t -> l, k);
}

void insert(node *&t, node *&nd){
  if(has(t, nd -> v)) return;
  node *l = NULL, *r = NULL;
  split(t, nd -> v, l, r);
  merge(t, l, nd);
  merge(t, t, r);
}

void insert(node *&t, int x){
  node *nd = new node(x, rand());
  insert(t, nd);
  nd = NULL;
}

void remove(node *&t, int x){
  if(t == NULL) return;
  node *l=NULL, *ll=NULL, *lr=NULL, *r=NULL;
  split(t, x, l, r);
  split(l, x - 1, ll, lr);
  merge(t, ll, r);
}

int k_ele(node *t, int k){
  if(t == NULL || t -> cnt < k) return -1;
  if(t -> l == NULL){
    if(k == 1)  return t -> v;
    return k_ele(t -> r, k - 1);
  }
  if(t -> l -> cnt == k - 1) return t -> v;
  if(t -> l -> cnt >= k)  return k_ele(t -> l, k);
  return k_ele(t -> r, k - (t -> l -> cnt) - 1);
}

int calc_mx(node *&t, int i, int j){
  if(i == j)  return -1;
  return k_ele(t, j) - k_ele(t, i);
}

int calc_min(node *&t, int i, int j){
  int ans;
  if(i == j)  return -1;

  node *l = NULL, *r = NULL, *rl = NULL, *rr = NULL;

  int beg = k_ele(t, i), end = k_ele(t, j);
  split(t, beg - 1, l, r);
  split(r, end, rl, rr);
  ans = rl -> ans;
  //cout << "ans: " << ans << " " << (rl -> l -> ans) << "\n";
  //print(rl);
  //cout << "\n";
  merge(r, rl, rr);
  merge(t, l, r);
  return ans;
}


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  char op[5];
  int n, x, y;
  node *t = NULL;
  srand(time(NULL));
  cin >> n;

  for(int i = 1; i <= n; ++i){
    cin >> op >> x;
    if(op[0] == 'I') insert(t, x);
    else if(op[0] == 'D')  remove(t, x);
    else{
      cin >> y;
      if(op[0] == 'N') cout << calc_min(t, x + 1, y + 1) << "\n";
      else cout << calc_mx(t, x + 1, y + 1) << "\n";
    }
  }

  return 0;
}
