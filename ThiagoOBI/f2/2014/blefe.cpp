#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

vector <pll> val;
vector <ll> a, b;
vector <bool> ok;
int main(){
  int n, m, aux;
  scanf("%d %d", &n, &m);
  a.assign(n, 0);
  b.assign(m, 0);
  ok.assign(m, 0);
  for(int i = 0; i < n; ++i)  scanf("%lld", &a[i]);
  for(int i = 0; i < m; ++i){
    scanf("%lld", &b[i]);
    val.push_back(pll(b[i], i));
  }
  sort(a.begin(), a.end());
  sort(val.begin(), val.end());
  for(int i = 0, j = 0; i < a.size(); ++i){
    while(j < m && val[j].ff < a[i]) ++j;
    while(j < m && val[j].ff == a[i])  ok[val[j].ss] = 1, ++j;
  }
  for(int i = 0; i < m; ++i){
    if(i > 0 && val[i].ff == val[i - 1].ff)  continue;
    aux = 0;
    for(int j = i; j < m; ++j){
      if(j > 0 && val[j].ff == val[j - 1].ff)  continue;

      while(aux < m && val[aux].ff < val[j].ff + val[i].ff) ++aux;
      while(aux < m && val[aux].ff == val[i].ff + val[j].ff){
        if(val[aux].ss > max(val[i].ss, val[j].ss)) ok[val[aux].ss] = 1;
        ++aux;
      }

    }

  }

  for(int i = 0; i < m; ++i)
    if(!ok[i]){
      printf("%lld\n", b[i]);
      return 0;
    }

  printf("sim\n");
  return 0;
}
