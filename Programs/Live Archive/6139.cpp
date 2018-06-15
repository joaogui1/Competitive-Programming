#include <bits/stdc++.h>
using namespace std;

int ft[2][100100], x[100100];

void upd(int x, int val, int idx){
  for(; x < 100100; x += x&-x)  ft[idx][x] += val;
}

int query(int x, int idx){
  int ret = 0;
  for(; x > 0; x -= x&-x) ret += ft[idx][x];
  return ret;
}

int query(int x, int y, int idx){
  return query(y, idx) - query(x - 1, idx);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  char op;
  int n, k, a, b, c;
  while(cin >> n >> k){
    memset(ft, 0, sizeof ft);
    for(int i = 1; i <= n; ++i){
      cin >> x[i];
      if(x[i] < 0)  upd(i, 1, 0);
      if(x[i] == 0) upd(i, 1, 1);
    }
    while(k--){
      cin >> op >> a >> b;
      if(op == 'C'){
        if(x[a] == b) continue;
        if(b == 0){
          upd(a, 1, 1);
          if(x[a] < 0)  upd(a, -1, 0);
        }
        else if(b < 0){
          if(x[a] >= 0)  upd(a, 1, 0);
          if(x[a] == 0) upd(a, -1, 1);
        }
        else{
          if(x[a] < 0) upd(a, -1, 0);
          if(x[a] == 0) upd(a, -1, 1);
        }
        x[a] = b;
      }
      else{
        if(query(a, b, 1) != 0) cout << '0';
        else{
          c = query(a, b, 0);
          if(!(c&1))  cout << '+';
          else  cout << '-';
        }
      }
    }
    cout << '\n';
  }
  return 0;
}
