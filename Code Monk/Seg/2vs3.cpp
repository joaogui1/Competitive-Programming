#include <bits/stdc++.h>

using namespace std;
int ft[100100], v[100100];

void update(int x, int v){
  for(; x < 100100; x += x&(-x))
    ft[x] += v;

  return;
}

int query(int x){
  int ret = 0;
  for(; x > 0; x -= x&(-x)) ret += ft[x];
  return ret;
}

int query(int x, int y){
  return query(y) - query(x - 1);
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, q, op, aux, auy, ans;
  string input;
  cin >> n >> input;
  for(int i = 0; i < n; ++i)  v[n - i] = (input[i] - '0');
  for(int i = 1; i <= n; ++i){
    update(i, (((i + 1)%2) + 1)*v[i]);
  }

  cin >> q;
  while(q--){
    cin >> op;
    if(op == 0){
      cin >> aux >> auy;
      aux = n - aux;
      auy = n - auy;
      ans = query(auy, aux)%3;
      if((auy)%2 == 0 && ans != 0)  ans = 3 - ans;
      cout << ans << endl;
    }
    else{
      cin >> aux;
      if(input[aux] == '0'){
        input[aux] = '1';
        //cout << aux << endl;
        aux = n - aux;
        update(aux, ((aux + 1)%2 + 1));
      }
    }
  }


  return 0;
}
