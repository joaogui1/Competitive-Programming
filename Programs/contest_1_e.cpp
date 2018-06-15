#include <bits/stdc++.h>

using namespace std;

int v[100100];

struct node{
  int v;
  node *l, *r;
  node(){}
  node(int _v){
    v = _v;
    l = NULL;
    r = NULL;
  }
};

void insert(node *&t, int val){
  if(t -> v > val){
    if(t -> l == NULL)  t -> l = new node(val);
    else  insert(t -> l, val);
  }
  else{
    if(t -> r == NULL)  t -> r = new node(val);
    else  insert(t -> r, val);
  }
}

int father(node *t, int v){
  if((t -> l != NULL && (t -> l -> v) == v) || (t -> r != NULL && (t -> r -> v) == v))  return t -> v;
  if(v < (t -> v))  return father(t -> l, v);
  return father(t -> r, v);
}

void print(node *t){
  if(t == NULL) return;
  print(t -> l);
  cout << t -> v << " ";
  print(t -> r);
}

node *t;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, x, q;
  cin >> n;
  cin >> x;
  t = new node(x);
  v[1] = x;
  for(int i = 1; i < n; ++i){
    cin >> x;
    v[i + 1] = x;
    insert(t, x);
  }

  cin >> q;
  for(int i = 0; i < q; ++i){
    cin >> x;
    cout << father(t, v[x]) << " \n"[i == q - 1];
  }


  return 0;
}
