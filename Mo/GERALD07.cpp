#include <bits/stdc++.h>
#define ff first
#define ss second
#define MAXSQ 500

using namespace std;
typedef pair <int, int> pii;
typedef pair <pii, int> ppi;
typedef pair <ppi, ppi> ppp;

int ans[200100];
int block, compo;
vector<pii> snap;
vector <pii> edges;
vector <ppi> queries;
int p[200100], r[200100];
vector <ppi> bucket[200100];

int find(int x){
  return (x == p[x])?x:find(p[x]);
}

void join_r(int x, int y){
  x = find(x), y = find(y);
  if(x == y)  return;
  --compo;
  //cout << compo << endl << endl;
  if(r[x] > r[y]){
    snap.push_back(pii(y, -1));
    p[y] = x;
    return;
  }
  else if(r[x] == r[y]){
    snap.push_back(pii(y, x));
    p[y] = x;
    ++r[x];
    return;
  }
  snap.push_back(pii(x, -1));
  p[x] = y;
  return;
}

void join(int x, int y){
  x = find(x), y = find(y);
  if(x == y)  return;
  --compo;
  if(r[x] > r[y]){
    p[y] = x;
    return;
  }
  else if(r[x] == r[y]){
    p[y] = x;
    ++r[x];
    return;
  }
  p[x] = y;
  return;
}

void roll_back(int t){
  int sz = snap.size();
  while(t--){
    --sz;
    ++compo;
    p[snap[sz].ff] = snap[sz].ff;
    if(snap[sz].ss > -1)  --r[snap[sz].ss];
    snap.pop_back();
  }
}

inline bool comp(ppi a, ppi b){
  return a.ff.ss < b.ff.ss;
}

void initialize(){
  snap.clear();
  edges.clear();
  memset(ans, 0, sizeof ans);
  queries.clear();
  for(int i = 0; i < 200100; ++i) bucket[i].clear();
  for(int i = 0; i < 200100; ++i) p[i] = i, r[i] = 0;
}

int main(){
  ios_base::sync_with_stdio(0);
  pii cur;
  int t, n, m, q, a, b, me, rr;
  cin >> t;
  while(t--){
    initialize();
    cin >> n >> m >> q;

    for(block = 1; block*block <= m; ++block);
    --block;
    for(int i = 0; i < m; ++i){
      cin >> a >> b;
      --a, --b;
      edges.push_back(pii(a, b));
    }

    for(int i = 0; i < q; ++i){
      cin >> a >> b;
      --a, --b;
      if(a > b) swap(a, b);
      //queries.push_back(ppi(pii(a, b), i));
      bucket[a/block].push_back(ppi(pii(a, b), i));
    }

    for(int i = 0; i < MAXSQ; ++i)  sort(bucket[i].begin(), bucket[i].end(), comp);

    for(int i = 0; i < MAXSQ; ++i){
      compo = n;
      me = (i + 1)*block - 1;
      for(int j = 0; j < n; ++j)  p[j] = j, r[j] = 0;

      for(int j = 0; j < bucket[i].size(); ++j){
        cur = bucket[i][j].ff;

        if(cur.ss < (i + 1)*block){
          for(int k = cur.ff; k <= cur.ss; ++k) join_r(edges[k].ff, edges[k].ss);
          ans[bucket[i][j].ss] = compo;
          roll_back(snap.size());
          continue;
        }

        else{
          for(int k = me + 1; k <= cur.ss; ++k)  join(edges[k].ff, edges[k].ss);
          me = cur.ss;

          for(int k = (i + 1)*block; k >= cur.ff; --k)  join_r(edges[k].ff, edges[k].ss);

          ans[bucket[i][j].ss] = compo;
          roll_back(snap.size());
        }

      }
      roll_back(snap.size());
    }

    for(int i = 0; i < q; ++i)  cout << ans[i] << "\n";

  }

  return 0;
}
