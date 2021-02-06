#include <bits/stdc++.h>
#define MAXN 10000000

using namespace std;
typedef long long int ll;

int maxprime[MAXN + 5], beg = 2;
ll dp[MAXN + 5], phi[MAXN + 5];

void find_primes(int n){
  for(int i = 2; i * i <= n; ++i)
    if(maxprime[i] == 0)
      for(int j = 2*i; j <= n; j += i)
        maxprime[j] = i;
  return;
  //for(int i = 2; i <= n; ++i) if(minprime[i] == 0) minprime[i] = i;
}


int main(){
  ios_base::sync_with_stdio(0);
  int t, n, aux, p;
  cin >> t;
  dp[1] = phi[1] = 1;
  find_primes(MAXN);

  for(int i = 2; i <= MAXN; ++i){
    aux = i;
    p = maxprime[aux];
    if(p == 0)  phi[i] = aux - 1;
    else{
      for(; aux % p == 0; aux /= p);
      phi[i] = phi[aux];
      phi[i] *= i;
      phi[i] *= (p - 1);
      phi[i] /= (p*aux);
    }
  }

  for(int i = 2; i <= MAXN; ++i)  dp[i] = dp[i - 1] + phi[i];

  while(t--){
    cin >> n;
    cout << dp[n] << "\n";
  }
  //cout << "{";
  //for(int i = 1; i < 100; ++i)  cout << f(i*100000) << " ,";
  //cout << f(10000000) << "}\n";
  return 0;
}
