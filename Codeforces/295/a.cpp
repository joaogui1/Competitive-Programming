#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<pair<int, int>, ll> ppl;

ppl ops[100010];
ll a[100010], diff[100010], ops_diff[100010], aux;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll n, m, k, x, y;
  cin >> n >> m >> k;
  for(int i = 1; i <= n; ++i)  cin >> a[i];
  for(int i = 1; i <= n; ++i)  diff[i] = a[i] - a[i - 1];
  for(int i = 1; i <= m; ++i)
    cin >> ops[i].ff.ff >> ops[i].ff.ss >> ops[i].ss;
  for(int i = 0; i < k; ++i){
    cin >> x >> y;
    ++ops_diff[x], --ops_diff[y + 1];
  }
  aux = 0;
  for(int i = 1; i <= m; ++i){
    aux += ops_diff[i];
    diff[ops[i].ff.ff] += aux*ops[i].ss;
    diff[ops[i].ff.ss + 1] -= aux*ops[i].ss;
  }

  aux = 0;
  for(int i = 1; i <= n; ++i)
    aux += diff[i], cout << aux << " \n"[i == n];



  return 0;
}
