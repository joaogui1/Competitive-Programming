#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector <ll> bases;
int is_happy[16][1 << 15], mark[16][1 << 15], ans[1 << 9];

ll sq_sum(ll x){
  int sq = 0;
  for(;x > 0; x /= 10LL)  sq += (x%10LL)*(x%10LL);
  return sq;
}

ll chbase(ll b, ll x){
  ll ret = 0;
  for(ll i = 1; x > 0; x /= b, i*= 10)  ret += (x % b)*i;
  return ret;
}

int dfs(int b, int x){
  //cout << b << " " << x << endl;
  if(x == 1)  return 1;
  if(is_happy[b][x] == 1) return 1;
  if(is_happy[b][x] == -1)  return -1;
  if(mark[b][x] == 1) return is_happy[b][x] = -1;
  mark[b][x] = 1;
  return  is_happy[b][x] = dfs(b, sq_sum(chbase(b, x)));
}

ll f(int mask){
  int beg = 2, b;
  for(int i = 0; i < 9; ++i)
    if(mask & (1 << i))
      beg = max(beg, ans[mask & ~(1 << i)]);
  //cout << beg << " " << "Ok\n";
  for(int i = beg; i < (1 << 15); ++i)
    for(int j = 1; j < 9; ++j){
      if(mask & (1 << j)) b = j + 2;
      else if(j == 8) return ans[mask] = i;
      else  continue;
      if(dfs(b, i) == -1)  break;
    }

  return -1;
}

int main(){
  //ios_base::sync_with_stdio(0);
  int n, aux;
  string in;
  //cin >> n;
  //getline(cin, in);
  /*for(int t = 1; t <= n; ++t){
    bases.clear();
    getline(cin, in);
    stringstream ss(in);
    for(; ss >> aux; bases.push_back(aux));
    cout << f() << "\n";
  }*/
  ans[0] = ans[2] = 2;
  for(int i = 0; i < 9; ++i)  ans[1 << i] = 2;
  //cout << f(3) << endl;
  for(int i = 3; i < (1 << 9); ++i)
    cout << i << " " << f(i) << "\n";

  return 0;
}
