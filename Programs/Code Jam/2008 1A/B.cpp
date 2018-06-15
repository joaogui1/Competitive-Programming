#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <int, int> pii;

vector <int> ans;
int mark[1 << 11];
set <int> milk[1 << 11];
set <pii> costum[1 << 11];

void initialize(){
  ans.clear();
  memset(mark, 0, sizeof mark);
  for(int i = 0; i < (1 << 11); ++i)  milk[i].clear();
  for(int i = 0; i < (1 << 11); ++i)  costum[i].clear();
  return;
}

bool toposort(int n){
  int idx, m, st;
  queue <int> q;
  for(int i = 0; i < n; ++i)
    if(costum[i].size() == 1) q.push(i);

  while(q.size()){
    idx = q.front();q.pop();
    m = costum[idx].begin() -> ff;
    st = costum[idx].begin() -> ss;
    //cout << idx << " " << m << " " << st << "\n";
    if(mark[m] == st + 1) continue;
    else if(mark[m] != 0) return 0;

    mark[m] = st + 1;

    for(const int &v : milk[m])
      if(costum[v].count(pii(m, !st))){
        costum[v].erase(pii(m, !st));
        if(costum[v].size() == 1) q.push(v);
        if(costum[v].size() == 0) return 0;
      }
  }
  return 1;
}

int main(){
  ios_base::sync_with_stdio(0);
  int c, n, m, sz, aux, auy;
  cin >> c;
  for(int t = 1; t <= c; ++t){
    initialize();
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
      cin >> sz;
      for(int j = 0; j < sz; ++j){
        cin >> aux >> auy;
        --aux;
        milk[aux].insert(i);
        costum[i].insert(pii(aux, auy));
      }
    }
    cout << "Case #" << t << ": ";
    if(!toposort(m))  cout << "IMPOSSIBLE\n";
    else  for(int i = 0; i < n; ++i)  cout << ((mark[i] == 0)?0:mark[i] - 1) << " \n"[i + 1 == n];

  }

  return 0;
}
