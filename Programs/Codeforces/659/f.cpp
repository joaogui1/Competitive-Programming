#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair <ll, ll> pii;
typedef pair <ll, pii> ppi;

vector <ppi> v;
ll p[1 << 20], r[1 << 20], ans, cont = 0;
ll G[1 << 10][1 << 10], dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, mark[1 << 10][1 << 10], n, m;

bool lim(int x, int y){
  return (x > -1 && y > -1 && x < n && y < m);
}

bool lim(pii x){
  return lim(x.ff, x.ss);
}

void dfs(int x, int y, ll val){
  ++cont;
  mark[x][y] = 1;
  for(int i = 0; i < 4; ++i)
    if(lim(x + dx[i], y + dy[i]) && mark[x + dx[i]][y + dy[i]] != 1 && G[x + dx[i]][y + dy[i]] >= val && cont < ans)
      dfs(x + dx[i], y + dy[i], val);
  return;
}

void dfs(pii x, ll val){
  dfs(x.ff, x.ss, val);
  return;
}

int find(int x){
  return (x == p[x])?p[x]:p[x] = find(p[x]);
}

int find(pii x){
  return find(m*x.ff + x.ss);
}

void join(int x, int y){
  x = find(x), y = find(y);
  if(x == y)  return;
  if(r[x] > r[y]){
    p[y] = x;
    r[x] += r[y];
  }
  else{
    p[x] = y;
    r[y] += r[x];
  }
  return;
}

void join(pii x, pii y){
  join(m*x.ff + x.ss, m*y.ff+ y.ss);
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  pii aup;
  ll k, val;
  cin >> n >> m >> k;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
      cin >> G[i][j];
      v.push_back(ppi(G[i][j], pii(i, j)));
    }

  sort(v.rbegin(), v.rend());
  for(int i = 0; i < v.size(); ++i) p[i] = i, r[i] = 1;

  for(int i = 0; i < v.size(); ++i){
    for(int j = 0; j < 4; ++j){
      aup.ff = v[i].ss.ff + dx[j];
      aup.ss = v[i].ss.ss + dy[j];
      if(lim(aup) && v[i].ff <= G[aup.ff][aup.ss])
        join(v[i].ss, aup);
    }


    if(r[find(v[i].ss)]*v[i].ff >= k && k % v[i].ff == 0){
      val = v[i].ff;
      ans = k/v[i].ff;
      dfs(v[i].ss, v[i].ff);
      break;
    }

  }

  if(ans == 0)  cout << "NO\n";
  else{
    cout << "YES\n";
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j){
        if(mark[i][j] == 1 && ans > 0){
          cout << val << " \n"[j == m - 1];
          --ans;
        }
        else  cout << 0 << " \n"[j == m - 1];
      }
  }

  return 0;
}
