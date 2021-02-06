#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

set <ll> ans;
int is_comp[1000010];
void sieve(){
  for(long long int i = 2LL; i <= 1000000; ++i){
    if(!is_comp[i]){
      for(int j = 2*i; j <= 1000000; j += i)  is_comp[j] = 1;
      ans.insert(i*i);
    }
  }
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  sieve();
  ll n, x, sq;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> x;
    if(ans.count(x))  cout << "YES\n";
    else  cout << "NO\n";
  }

  return 0;
}
