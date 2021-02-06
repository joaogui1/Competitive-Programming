#include <bits/stdc++.h>

using namespace std;

struct node{
  int v, p, sz;
  node *l, *r;
  node(){}
  node(int _v, int _p){
    v = _v;
    p = _p;
    sz = 1;
    l = r = NULL;
  }
};

void upd(node *nd){
  if(nd == NULL)  return;
  nd -> sz = 1;
  if(nd -> l != NULL) nd -> sz += (nd -> l) -> sz;
  if(nd -> r != NULL) nd -> sz += (nd -> r) -> sz;
}

void split(node *t, int val, node *&l, node *&r){
  if(t == NULL){
    l = r = NULL;
    return;
  }
  if(t -> v < val){
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
    return;
  }
  if(l -> p > r -> p){
    merge(l -> r, l -> r, r);
    t = l;
  }
  else{
    merge(r -> l, l, r -> l);
    t = r;
  }
  upd(t);
}

void insert(node *&t, node *nd){
  if(t == NULL){
    t = nd;
    return;
  }
  if(t -> v == nd -> v) return;
  if(nd -> p < t -> p){
    if(nd -> v < t -> v)
      insert(t -> l, nd);
    else
      insert(t -> r, nd);
  }
  else{
    split(t, nd -> v, nd -> l, nd -> r);
    t = nd;
  }
  upd(t);
}

void erase(node *&t, int key){
  if(t == NULL) return;
  node *l, *ll, *lr, *r;
  split(t, key + 1, l, r);
  split(l, key, ll, lr);
  merge(t, ll, r);
}

int k_ele(node *t, int k){
  if(t == NULL) return -1;
  if(t -> sz < k) return -1;
  if(t -> l == NULL){
    if(k == 1)  return t -> v;
    return k_ele(t -> r, k - 1);
  }
  if(t -> l -> sz == k - 1) return t -> v;
  if(t -> l -> sz >= k)  return k_ele(t -> l, k);
  return k_ele(t -> r, k - (t -> l -> sz) - 1);
}

int count(node *t, int k){
  int ret;
  if(t == NULL) return 0;
  node *l, *r;
  split(t, k, l, r);
  ret = (l == NULL)?0:l -> sz;
  merge(t, l, r);
  return ret;
}

bool cnt(node *t, int k){
  if(t == NULL) return 0;
  if(t -> v == k) return 1;
  if(t -> v < k)  return cnt(t -> r, k);
  return cnt(t -> l, k);
}

node *t;

int main(){
  srand(time(0));
  int q, k;
  char op;
  scanf("%d", &q);
  while(q--){
    scanf(" %c %d", &op, &k);
    if(op == 'I')
      if(!cnt(t, k)){
        node *nv = new node(k, rand());
        insert(t, nv);
      }
    if(op == 'D')
      if(cnt(t, k))
        erase(t, k);
    if(op == 'C')
      printf("%d\n", count(t, k));
    if(op == 'K'){
      if(k_ele(t, k) == -1) printf("invalid\n");
      else  printf("%d\n", k_ele(t, k));
    }
  }
  return 0;
}
