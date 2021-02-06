#include <bits/stdc++.h>
#define MOD 1000000007 

using namespace std;
int pai[1 << 10];
vector <int> risk, son[1 << 10];

int find(int x){
  return pai[x] = (x == pai[x])?(x):(find(pai[x]));
}

int join(int x, int y){
  return pai[find(x)] = find(y);
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, m, aux, auy, aux_min, v;
  long long int ans = 1, cont;
  cin >> n;

  for(int i = 0; i <= n; ++i) pai[i] = i;
  risk.push_back(0);
  for(int i = 0; i < n; ++i){
    cin >> aux;
    risk.push_back(aux);
  }
  cin >> m;
  for(int i = 0; i < m; ++i){
    cin >> aux >> auy;
    if(find(aux) != find(auy))  join(aux, auy);
  }
  for(int i = 1; i <= n; ++i) son[find(i)].push_back(i);

  /*for(int i = 1; i <= n; ++i)
    for(int j = 0; j < son[i].size(); ++j)
      cout << son[i][j] << " \n"[j == son[i].size() - 1];*/

  for(int i = 1; i <= n; ++i){
    aux_min = 1 << 11;
    cont = 1;
    for(int j = 0; j < son[i].size(); ++j){
      v = son[i][j];
      if(risk[v] < aux_min){
        aux_min = risk[v];
        cont = 1;
      }
      else if(risk[v] == aux_min) ++cont;
    }
    //cout << i << " " << cont << endl;
    ans *= cont;
    ans %= MOD;
  }

  cout << ans << "\n";

  return 0;
}
