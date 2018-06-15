#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, string > pis;

int key[32], chest[128], prize[128], n, k, m, cont = 0;

map<pis, int> dp;

bitset<101> b, aux;

int gcd(int a, int b){
  return (b == 0) ? a : gcd(b, a % b);
}

int f(int chave, int mask, bitset<101> closed){
  if(chave >= k) return 0;

  pis P = pis(pii(chave, mask), closed.to_string());

  if(dp.count(P)) return dp[P];

  int idx = -1;
  for(int i = 0; i < n; ++i)
    if((1 << i) & mask){
      idx = i;
      break;
    }
  if(idx == -1) return 0;

  int add = 0;
  aux = closed;
  for(int i = 0; i < m; ++i)
    if(aux[i])
      if(gcd(chest[i], key[idx]) != 1){
        aux[i] = 0;
        add += prize[i];
      }


  return dp[P] =  max(f(chave, mask & ~(1 << idx), closed), f(chave + 1, mask & ~(1 << chave), aux) + add);

}
void initialize(int n, int k){
  b.set();
  dp.clear();
  //memset(key, 0, sizeof key);
  //memset(chest, 0, sizeof chest);
  //memset(prize, 0, sizeof prize);
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--){
    cin >> n >> m >> k;
    initialize(n, k);

    for(int i = 0; i < n; ++i)  cin >> key[i];
    for(int i = 0; i < m; ++i)  cin >> chest[i];
    for(int i = 0; i < m; ++i)  cin >> prize[i];

    cout << f(0, (1 << n) - 1, b) << "\n";
    //for(auto e : dp)
      //cout << e.first.first.first << " " << e.first.first.second << " " << e.first.second << " " << e.second << endl;
  }


  return 0;
}
