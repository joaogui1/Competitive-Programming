#include <bits/stdc++.h>
#define pb push_back

using namespace std;

queue <int> q;
vector <int> ans;
int dep[1 << 10];
vector <int> adj[1 << 10];

bool toposort(int n){
  int aux;
  for(int i = 0; i < n; ++i)
    if(dep[i] == 0) q.push(i);
  if(q.size() > 1)  return 0;
  while(q.size()){
    aux = q.front();q.pop();
    ans.pb(aux);
    for(int const v : adj[aux]){
      --dep[v];
      if(dep[v] == 0) q.push(v);
    }
    if(q.size() > 1)  return 0;
  }
  return 1;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, k, a, b;
  cin >> n >> k;
  for(int i = 0; i < k; ++i){
    cin >> a >> b;
    adj[a].pb(b);
    ++dep[b];
  }

  if(!toposort(n))  cout << "back to the lab\n";
  else for(int const v : ans) cout << v << " \n"[v == ans[ans.size() - 1]];

  return 0;
}
