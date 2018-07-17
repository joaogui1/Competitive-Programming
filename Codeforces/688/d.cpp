#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pii;

bool is_comp[1000100];
vector <int> divi, primes, ancient;

void pre(){
  for(int i = 2; i < 1000100; ++i)
    if(!is_comp[i]){
      primes.push_back(i);
      for(int j = 2*i; j < 1000100; j+= i)  is_comp[j] = 1;
    }
  return;
}

void divide(int n){
  int d = 1;
  for(int i = 0; i < primes.size(); ++i){
    d = 1;
    while(n % primes[i] == 0){
      d *= primes[i];
      n /= primes[i];
    }
    if(d != 1)  divi.push_back(d);
  }
}
//k == 1
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  pre();
  int n, k, c, vdc = 0;
  cin >> n >> k;
  divide(k);
  for(int i = 0; i  < n; ++i){
    cin >> c;
    ancient.push_back(c);
  }
  for(int i = 0; i < divi.size(); ++i){
    vdc = 0;
    for(int j = 0; j < ancient.size(); ++j){
      if((ancient[j] % divi[i]) == 0){
        vdc = 1;
        break;
      }
    }
    if(!vdc){
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}
