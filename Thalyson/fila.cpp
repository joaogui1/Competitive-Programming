#include <bits/stdc++.h>

using namespace std;

struct node{
  int v, p, big, cnt;
  node *l, *r;

  node(){}
  node(int _v){
    cnt = 1;
    big = v = _v;
    p = rand();
    l = r = NULL;
  }
};

int fbig(node *&t){
  if(t == NULL) return 0;
  return t -> big;
}

int fcnt(node *&t){
  if(t == NULL) return 0;
  return t -> cnt;
}

void up(node *&t){
  if(t == NULL) return;
  t -> cnt = fcnt(t -> l) + 1 + fcnt(t -> r);
  t -> big = max(t -> v, max(fbig(t -> l), fbig(t -> r)));
}

void split(node *t, node *&l, node *&r, int pos){
  if(t == NULL){
    l = r = NULL;
    return;
  }
  else if(fcnt(t -> l) < pos){
    split(t -> r, t -> r, r, pos - fcnt(t -> l) - 1);
    l = t;
  }
  else{
    split(t -> l, l, t -> l, pos);
    r = t;
  }
  up(t);
}

void merge(node *&t, node *l, node *r){
  if(l == NULL || r == NULL)
    t = (l == NULL)?r:l;

  else if(l -> p >= r -> p){
    merge(l -> r, l -> r, r);
    t = l;
  }
  else{
    merge(r -> l, l, r -> l);
    t = r;
  }
  up(t);
}

void insert(node *&t, int v, int p){
  node *l = NULL, *r = NULL, *nd = NULL;
  nd = new node(v);
  split(t, l, r, p);
  merge(t, l, nd);
  merge(t, t, r);
}

int query(node *t, int h, int p){
  int ret = 0;
  node *l = NULL, *r = NULL, *lr = NULL, *rr = NULL, *aux = NULL;
  split(t, l, r, p - 1);
  split(r, lr, rr, 1);
  aux = l;
  h += (lr -> v);
  if(!fcnt(aux) || fbig(aux) <= h)  return 0;
  while(aux -> cnt > 1){
    if(fbig(aux -> r) > h)  ret += fcnt(aux -> l) + 1, aux = aux -> r;
    else if(aux -> v > h){
      ret += fcnt(aux -> l);
      break;
    }
    else  aux = aux -> l;
  }
  ++ret;
  merge(r, lr, rr);
  merge(t, l, r);
  return ret;
}

void printt(node *t){
  if(t == NULL) return;
  printt(t -> l);
  cout << (t -> v) << " ";
  printt(t -> r);
}

void print(node *t){
  printt(t);
  cout << "\n";
}

node *t = NULL;

int main(){
  srand(time(NULL));
  int n, q, x, op, p;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &x);
    insert(t, x, i);
  }
  scanf("%d", &q);
  for(int i = 0; i < q; ++i){
    scanf("%d %d %d", &op, &p, &x);
    if(!op) insert(t, x, p);
    else  printf("%d\n", query(t, x, p));
  }

  return 0;
}
