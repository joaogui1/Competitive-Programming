#include <bits/stdc++.h>
#define INF (1LL << 50)

using namespace std;
typedef long long int ll;

ll dp[4][10100], s, e, a;

ll g(ll x, ll y, bool p){ //custo quando voce so tem 1 ovoe tem que checar de x a y
    if(y < x) return 0;

    ll ret = 0;
    ll qtd = y - x;
    ret += (qtd + 1)*e;
    ret += x*s*qtd;
    ret += (s*(qtd*(qtd+1)))/2;
    if(!p) ret += s*x;
    return ret;
}

ll f(ll eggs, ll x){
  if(x > a) return 0; //andar muito alto
  if(x == a)  return e; //ultimo andar
  if(dp[eggs][x] != INF) return dp[eggs][x];

  for(ll i = x; i < a; ++i){
    ll delta = (i - x)*s + e; //custo de subir e jogar um ovo

    ll quebra = g(x, i - 1, eggs);

    ll pega = f(1, i + 1) + (i + 1)*s;

    ll nao_pega = INF;
    if(eggs) nao_pega = s + f(0, i + 1);

    dp[eggs][x] = min(dp[eggs][x], delta + max(quebra, min(pega, nao_pega)));
  }
  return dp[eggs][x];
}

int main(){
  scanf("%lld %lld %lld", &a, &s, &e);
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j <= a; ++j) dp[i][j] = INF;
  printf("%lld\n", s + f(1, 1));
  return 0;
}
