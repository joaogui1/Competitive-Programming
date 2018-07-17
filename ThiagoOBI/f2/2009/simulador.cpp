#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int inv[3024][4];

ll sum(ll x, ll y){
  if(x > y) swap(x, y);
  return y*(y + 1LL)/2LL - x*(x - 1LL)/2LL;
}

ll f(ll x, ll y, ll cont){
  if(y < x) return 0;
  if(cont == 0) return sum(x, y);
  ll aux = inv[cont][0], auy = inv[cont][1];
  if((x > auy || y < aux) || (x <= aux && auy <= y))  return f(x, y, cont - 1);
  if(auy <= y)  return f(auy + 1, y, cont - 1) + f(aux, aux + auy - x, cont - 1);
  if(x <= aux)  return f(x, aux - 1, cont - 1) + f(aux + auy - y, auy, cont - 1);
  return f(aux + auy - y, aux + auy - x, cont - 1);
}

int main(){
  char op;
  ll aux, auy;
  int n, m, cont = 0;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i){
    scanf(" %c %lld %lld", &op, &aux, &auy);
    if(op == 'I'){
      inv[++cont][0] = aux;
      inv[cont][1] = auy;
    }
    else
      printf("%lld\n", f(aux, auy, cont));
  }


  return 0;
}
