#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll digits[70];
vector <ll> divi;

ll factor(ll x){
  if(x == 1) return -1;
  if(x == 2)  return -1;
  if(x%2 == 0)  return 2;
  for(ll i = 3; i*i <= x; i += 2)
    if(x % i == 0)  return i;
  return -1;
}

ll factor(){
  ll aux, ex = 1;
  for(ll i = 5; i <= 100LL; i += 2){
    aux = 0;
    ex = 1;
    for(ll j = 1; j < 33; ++j){
      if(digits[32 - j])  aux += ex;
      if(aux >= i)  aux %= i;
      ex *= 6;
      if(ex >= i) ex %= i;
      if(j == 32 && aux == 0) return i;
    }
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0);
  ll n, jj, aux, ex, cont = 0, auy;
  cin >> n >> jj;
  cout << "Case #1:\n";
  /*for(int i = 0; i < (1 << (n - 2)); ++i){
    divi.assign(16, 0);
    memset(digits, 0, sizeof digits);
    aux = 2*i + 1 + (1 << (n - 1));

    for(int q = 0; q < n; ++q)
      if(aux & (1 << q))
        digits[q] = 1;

    for(ll b = 2; b < 11; ++b){
      ex = 1;
      aux = 0;
      for(int i = 1; i <= n; ++i){
        if(digits[n - i]) aux += ex;
        ex *= b;
      }
      divi[b] = factor(aux);
      if(divi[b] == -1) break;
      if(b == 10){
        ++cont;
        cout << aux << " ";
        for(int q = 2; q < 11; ++q) cout << divi[q] << " \n"[q == 10];
      }
    }
    if(cont == j) break;
  }*/
  for(int i = 0; i < 30; ++i)
    for(int j = i + 1; j < 30; ++j)
      for(int k = j + 1; k < 30; ++k)
        for(int l = k + 1; l < 30; ++l){
          aux = (1LL << i) + (1LL << j) + (1LL << k) + (1LL << l);
          aux << 1LL;
          aux += (1LL << 31);
          if(aux % 3 != 0)  continue;
          memset(digits, 0, sizeof digits);
          digits[0] = digits[31] = 1;
          digits[i + 1] = digits[j + 1] = digits[k + 1] = digits[l + 1] = 1;
          auy = factor();
          if(auy != -1){
            ++cont;
            for(int i = 1; i <= 32; ++i)
              cout << digits[32 - i];
            cout << " ";
            cout << 3 << " " << 2 << " " << 3 << " " << 2 << " " << auy << " " << 2 << " " << 3 << " " << 2 << " " << 3 << "\n";
          }
          if(cont == jj) return 0;
        }

  return 0;
}
