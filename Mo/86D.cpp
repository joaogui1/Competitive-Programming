#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;
typedef pair<pii, ll> ppi;

ll block;
vector<ppi> q;
vector <ll> ans;
ll freq[1000010], v[1000010];

bool comp(ppi a, ppi b){
  if((a.ff.ff/block) ^ (b.ff.ff/block)) return a.ff.ff < b.ff.ff;
  return a.ff.ss < b.ff.ss;
}

int main(){
  //cin.tie(0);
  //ios_base::sync_with_stdio(0);
  pii cur;
  ll a, p = 0;
  int n, t, mb = 0, me = -1;
  //cin >> n >> t;
  scanf("%I64d %I64d", &n, &t);
  ans.assign(t, 0);
  for(block = 1; block*block <= t; ++block);
  --block;
  for(int i = 0; i < n; ++i){
    //cin >> a;
    scanf("%I64d", &a);
    v[i] = a;
  }
  for(int i = 0; i < t; ++i){
    scanf("%I64d %I64d", &mb, &me);
    --mb, --me;
    q.push_back(ppi(pii(mb, me), i));
  }
  sort(q.begin(), q.end(), comp);

  mb = 0, me = -1;
  for(int i = 0; i < t; ++i){
    cur = q[i].ff;
    while(mb < cur.ff){
      p -= freq[v[mb]]*freq[v[mb]]*v[mb];
      --freq[v[mb]];
      p += freq[v[mb]]*freq[v[mb]]*v[mb];
      ++mb;
    }

    while(mb > cur.ff){
      --mb;
      p -= freq[v[mb]]*freq[v[mb]]*v[mb];
      ++freq[v[mb]];
      p += freq[v[mb]]*freq[v[mb]]*v[mb];
    }

    while(me > cur.ss){
      p -= freq[v[me]]*freq[v[me]]*v[me];
      --freq[v[me]];
      p += freq[v[me]]*freq[v[me]]*v[me];
      --me;
    }

    while(me < cur.ss){
      ++me;
      p -= freq[v[me]]*freq[v[me]]*v[me];
      ++freq[v[me]];
      p += freq[v[me]]*freq[v[me]]*v[me];
    }
    //ans.push_back(pii(q[i].ss, p));
    ans[q[i].ss] = p;
  }
  //sort(ans.begin(), ans.end());
  for(int i = 0; i < t; ++i) //cout << ans[i].ss << "\n";
    printf("%I64d\n", ans[i]);
  return 0;
}
