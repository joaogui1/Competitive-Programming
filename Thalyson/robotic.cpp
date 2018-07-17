#include <bits/stdc++.h>

using namespace std;

map <int, int> mp;
vector <int> vec, cp;

struct node{
  int p, v, mn, cnt, lazy;
  node *l, *r;
  node(){}
  node(int _v){
    cnt = 1;
    lazy = 0;
    p = rand();
    mn = v = _v;
    l = r = NULL;
  }
};

int fcnt(node *t){
  if(t == NULL) return 0;
  return (t -> cnt);
}

int fmn(node *t){
  if(t == NULL) return (1 << 20);
  return (t -> mn);
}

void prop(node *t){
  if(t == NULL) return;
  (t -> lazy) %= 2;
  if(!(t -> lazy))  return;
  t -> lazy = 0;

  swap(t -> l, t -> r);

  if(t -> l != NULL)  ++(t -> l -> lazy);
  if(t -> r != NULL)  ++(t -> r -> lazy);
}

void up(node *t){
  if(t == NULL) return;

  t -> cnt = fcnt(t -> l) + 1 + fcnt(t -> r);
  t -> mn = min(t -> v, min(fmn(t -> l), fmn(t -> r)));
  prop(t);
}

void inv(node *t){
  if(t == NULL) return;
  ++(t -> lazy);
}

void split(node *t, node *&l, node *&r, int k){
  if(t == NULL){
    l = r =  NULL;
    return;
  }
  prop(t);
  if(fcnt(t -> l) < k){
    split(t -> r, t -> r, r, k - fcnt(t -> l) - 1);
    l = t;
  }
  else{
    split(t -> l, l, t -> l, k);
    r = t;
  }
  up(t);
}

void merge(node *&t, node *l, node *r){
  prop(l);
  prop(r);

  if(l == NULL || r == NULL)
    t = (l == NULL)?r:l;
  else if(l -> p > r -> p){
    merge(l -> r, l -> r, r);
    t = l;
  }
  else{
    merge(r -> l, l, r -> l);
    t = r;
  }
  up(t);
}

void insert(node *&t, int v){
  node *nd = new node(v);
  merge(t, t, nd);
}

void annihilate(node *&t){
  node *od = NULL;
  split(t, od, t, 1);
}

int find_min(node *t, int val){
  prop(t);
  if(t == NULL) return 0;
  if(t -> v == val) return fcnt(t -> l) + 1;
  if(fmn(t -> l) == val)  return find_min(t -> l, val);
  return fcnt(t -> l) + 1 + find_min(t -> r, val);
}

void faux(node *&t, int pos){
  node *l = NULL, *r = NULL;
  split(t, l, r, pos);
  inv(l);
  merge(t, l, r);
  annihilate(t);
}

void pre(int n){
  sort(cp.begin(), cp.end());
  for(int i = 0; i < n; ++i)
    if(!mp.count(cp[i]))
      mp[cp[i]] = i;

  for(int i = 0; i < n; ++i){
    ++mp[vec[i]];
    vec[i] = mp[vec[i]] - 1;
  }
}

void print(node *t){
  if(t == NULL) return;
  print(t -> l);
  cout << (t -> v) << " ";
  print(t -> r);
}

node *t, *l, *r;

void print(){

  print(t);
  cout << "\n";
}
void initialize(int n){
  t = l = r = NULL;
  mp.clear();
  cp.assign(n, 0);
  vec.assign(n, 0);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, pos;
  srand(time(NULL));

  while(cin >> n){
    if(n == 0)  return 0;
    initialize(n);
    for(int i = 0; i < n; ++i)  cin >> vec[i], cp[i] = vec[i];
    pre(n);

    for(int i = 0; i < n; ++i){
      insert(t, vec[i]);
      //print();
    }
    for(int i = 0; i < n; ++i){
      pos = find_min(t, i);
      faux(t, pos);
      cout << pos + i << " \n"[i == n - 1];
    }

  }


  return 0;
}
