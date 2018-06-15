#include <bits/stdc++.h>

using namespace std;

int pai[100100];

int find(int x){
  return ((pai[x] == x)?(x):(pai[x] = find(pai[x])));
}

void join(int x, int y){
  x = find(x), y = find(y);
  pai[x] = y;
  return;
}

void promote(int x){
  int aux = find(x);
  pai[x] = x;
  pai[aux] = x;
  find(aux);
  return;
}

void initialize(){
  for(int i = 0; i < 100100; ++i) pai[i] = i;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, q, a, b, op;
  cin >> n >> q;
  initialize();
  while(q--){
    cin >> op >> a;
    if(op == 1){
      cin >> b;
      join(a, b);
    }
    else if(op == 2)  promote(a);
    else  cout << find(a) << "\n";

  }

  return 0;
}
