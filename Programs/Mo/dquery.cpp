#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

int block;
vector<ppi> q;
vector <pii> ans;
int freq[1000010], v[1000010];

inline bool comp(ppi a, ppi b){
  if(a.ff.ff/block == b.ff.ff/block) return a.ff.ss < b.ff.ss;
  return a.ff.ff/block < b.ff.ff/block;
}

int main(){
  //ios_base::sync_with_stdio(0);
  pii cur;
  int n, t, mb = 0, me = -1, a, p = 0;;
  scanf("%d", &n);
  for(block = 1; block*block <= t; ++block);
  --block;
  for(int i = 0; i < n; ++i){
    scanf("%d", &a);
    v[i] = a;
  }
  scanf("%d", &t);
  for(int i = 0; i < t; ++i){
    scanf("%d %d", &mb, &me);
    --mb, --me;
    q.push_back(ppi(pii(mb, me), i));
  }
  sort(q.begin(), q.end(), comp);

  mb = 0, me = -1;
  for(int i = 0; i < t; ++i){
    cur = q[i].ff;
    while(mb < cur.ff){
      --freq[v[mb]];
      if(freq[v[mb]] == 0)  --p;
      ++mb;
    }

    while(mb > cur.ff){
      --mb;
      ++freq[v[mb]];
      if(freq[v[mb]] == 1)  ++p;
    }

    while(me > cur.ss){
      --freq[v[me]];
      if(freq[v[me]] == 0)  --p;
      --me;
    }

    while(me < cur.ss){
      ++me;
      ++freq[v[me]];
      if(freq[v[me]] == 1)  ++p;
    }
    ans.push_back(pii(q[i].ss, p));
  }
  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); ++i) printf("%d\n", ans[i].ss);

  return 0;
}
