#include <bits/stdc++.h>

using namespace std;

vector <int> ch[1000001];
int sz[1000001], p[1000001], s[1000001], smin[1000001];

int ft[1000001], n;

void upd(int x, int v){
  if(x == 0)  return;
  for(; x < 1000001; x += x&(-x)) ft[x] += v;
}

int query(int x){
  int ret = 0;
  for(; x > 0; x -= x&(-x)) ret += ft[x];
  return ret;
}

int search(int x){
	int resp=0;
  for(int i = 22; i >= 0; --i){
    int pot = (1<<i);
		int davez = resp + pot;
		if(davez > n) continue;
    if(ft[davez] < x){
      x -= ft[davez];
      resp = davez;
		}
	}

	return resp + 1;

	//return -1;
}


bool comp(int a, int b){
  return s[a] > s[b];
}

int dfs(int u){
  sz[u] = 1;
  for(int &v: ch[u])
    sz[u] += dfs(v);
  return sz[u];
}
priority_queue<int, vector<int>, decltype(&comp)> pq(comp);

int f(int u){ //retorna o numero de membros da subarvore de u determinados
  int ret = 0;
  smin[u] = search(sz[u]);
  // if(u == 6)  cout << query(s[p[u]] - 1) << " " << smin[u] << "\n";
  // cout << sz[u] << " " << smin[u] << "\n";
  if(sz[u] == query(s[p[u]] - 1)){
    ret = 1;
    s[u] = smin[u];
    upd(s[u], -1);
    for(int i = 0; i < ch[u].size(); ++i) ret += f(ch[u][i]);
  }
  return ret;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int ceo, aux, sm;
  cin >> n;
  for(int i = 1; i <= n; ++i) upd(i, 1);
  // for(int i = 1; i <= n; ++i) cout << query(i) << " \n"[i == n];
  for(int i = 1; i <= n; ++i){
    cin >> p[i] >> s[i];
    if(i == p[i]) ceo = i, s[i] = n;
    else  ch[p[i]].push_back(i);
    if(s[i] != 0){
      pq.push(i);
      upd(s[i], -1);
    }
  }
  dfs(ceo);

  while(pq.size()){
    sm = 0;
    aux = pq.top(), pq.pop();
    // cout << "pai " << aux << "\n";
    for(int &u: ch[aux])
      if(s[u] == 0) sm += f(u);
      else  sm += sz[u];
    if(sz[aux] - 1 - sm != 0 && sz[aux] - 1 - sm == query(s[aux])){
      // cout << "ok " << aux << "\n";
      // cout << sz[aux] - 1 - sm << "\n";
      for(int i = 0; i < sz[aux] - sm - 1; ++i)
        upd(search(1), -1);
    }
  }
  for(int i = 1; i <= n; ++i) cout << s[i] << "\n";
  return 0;
}
