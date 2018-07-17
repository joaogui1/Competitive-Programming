#include <bits/stdc++.h>

using namespace std;

vector<int> sum_k;
vector <int> adj[1000100];
int w[1000100], ent[1000100], exi[1000100], cnt = 0, trans[1000100];

void dfs(int u){
  int v;
  ent[u] = ++cnt;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    dfs(v);
    w[u] += w[v];
  }
  exi[u] = ++cnt;
  //trans[cnt] = u;
}



int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, aux, a, b;
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> aux >> w[i];
    adj[aux].push_back(i);
  }
  dfs(0);
  for(int i = 1; i <= n; ++i) trans[exi[i]] = i;
  if(w[0]%3 != 0){
    cout << "-1\n";
    return 0;
  }
  a = w[0]/3;
  for(int i = 1; i <= n; ++i)
    if(w[i] == a)  sum_k.push_back(exi[i]);
  sort(sum_k.begin(), sum_k.end());
  for(int i = 1; i <= n; ++i){
    if(w[i] != 2*a) continue;
    aux = (upper_bound(sum_k.begin(), sum_k.end(), ent[i]) - sum_k.begin());
    if(aux == sum_k.size() || sum_k[aux] >= exi[i]) continue;
    if(i == trans[sum_k[aux]])  continue;//cout << 1 << " ";
    cout << i << " " << trans[sum_k[aux]] << "\n";
    return 0;
  }
  for(int i = 1; i <= n; ++i){
    if(w[i] != a) continue;
    aux = (lower_bound(sum_k.begin(), sum_k.end(), ent[i]) - sum_k.begin());
    if(aux == 0)  continue;
    --aux;
    if(i == trans[sum_k[aux]])  cout << 2 << " ";
    cout << i << " " << trans[sum_k[aux]] << "\n";
    return 0;
  }
  cout << "-1\n";

  return 0;
}
