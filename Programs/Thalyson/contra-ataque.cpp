#include <bits/stdc++.h>
#define MAXD 810

using namespace std;

vector <int> adj[1 << 17];
int seg[3240][3240], pos[2][1 << 17], dp[1 << 17], is_root[1 << 17];

int query1(int idx, int node, int l, int r, int a, int b){
  if(r < a || l > b)  return -1;
  if(a <= l && r <= b)
    return  seg[idx][node];
  int m = (l + r)/2;
  return max(query1(idx, 2*node, l, m, a, b), query1(idx, 2*node + 1, m + 1, r, a, b));
}

int query2(int node, int l, int r, int xa, int xb, int ya, int yb){
  if(r < xa || l > xb)  return -1;
  if(xa <= l && r <= xb)
    return query1(node, 1, 1, MAXD, ya, yb);
  int m = (l + r)/2;
  return max(query2(2*node, l, m, xa, xb, ya, yb), query2(2*node + 1, m + 1, r, xa, xb, ya, yb));
}

void upd1(int idx, int node, int l, int r, int pos, int v){
  if(l > pos || r < pos)  return;
  if(l == r){
    seg[idx][node] = v;
    return;
  }

  int m = (l + r)/2;
  upd1(idx, 2*node, l, m, pos, v);
  upd1(idx, 2*node + 1, m + 1, r, pos, v);
  seg[idx][node] = max(seg[idx][2*node], seg[idx][2*node + 1]);
  return;
}

void merge(int tree, int node, int l, int r, int pos){
  if(l > r || l > pos || r < pos)  return;
  if(l != r){
    int m = (l + r)/2;
    merge(tree, 2*node, l, m, pos);
    merge(tree, 2*node + 1, m + 1, r, pos);
  }
  seg[tree][node] = max(seg[2*tree][node], seg[2*tree + 1][node]);
}

void upd2(int node, int l, int r, int posx, int posy, int v){
  if(l > r || l > posx || r < posx)  return;
  if(l == r){
    upd1(node, 1, 1, MAXD, posy, v);
    return;
  }
  int m = (l + r)/2;
  upd2(2*node, l, m, posx, posy, v);
  upd2(2*node + 1, m + 1, r, posx, posy, v);
  merge(node, 1, 1, MAXD, posy);
}

int dfs(int u){
  int v;
  dp[u] = 1 + query2(1, 1, MAXD, 1, pos[0][u] - 1, 1, pos[1][u] - 1);
  upd2(1, 1, MAXD, pos[0][u], pos[1][u], dp[u]);
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    dfs(v);
  }
  upd2(1, 1, MAXD, pos[0][u], pos[1][u], 0);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int a, b, c, d, n, m, ans = 0;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i)
    is_root[i] = 1;
  for(int i = 1; i <= n; ++i){
    cin >> pos[0][i] >> pos[1][i];
    pos[0][i] += 403;
    pos[1][i] += 403;
  }
  for(int i = 1; i <= m; ++i){
    cin >> a >> b;
    adj[b].push_back(a);
    is_root[a] = 0;
  }
  for(int i = 1; i <= n; ++i){
    if(is_root[i])
      dfs(i);
  }
  for(int i = 1; i <= n; ++i)
    ans = max(ans, dp[i]);
  cout << ans << "\n";
  return 0;
}
