#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <int, int> pii;
typedef pair <pii, int> ppi;

pii curr;
map <int, int> m;
int n, q, mb, me, ans = 0, cont = 0, sq;
int ft[20010], a[20010], pr[20010];
vector<ppi> queries;

bool cmp(ppi a, ppi b){
  if(a.ff.ff/sq == b.ff.ff/sq)  return a.ff.ss < b.ff.ss;
  return a.ff.ff < b.ff.ff;
}

void read(){
  cin >> n;
  for(sq = 1; sq*sq <= n; ++sq);
  --sq;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    m[a[i]] = 1;
  }
  for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
    it -> second = ++cont;
  for(int i = 0; i < n; ++i){
    a[i] = m[a[i]];
  }
  cin >> q;
  for(int i = 0; i < q; ++i){
    cin >> mb >> me;
    queries.push_back(ppi(pii(mb - 1, me - 1), i));
  }

  sort(queries.begin(), queries.end(), cmp);
}

void upd(int x, int v){
  for(; x < 20010; x += x&-x) ft[x] += v;
}

int query(int x){
  int ret = 0;
  for(; x > 0; x -= x&-x) ret += ft[x];
  return ret;
}

int query(int x, int trash){
  return  query(20008) - query(x);
}

void add_left(){
  upd(a[mb], 1);
  ans += query(a[mb] - 1);
}

void rm_left(){
  upd(a[mb], -1);
  ans -= query(a[mb] - 1);
}

void add_right(){
  upd(a[me], 1);
  ans += query(a[me], 1);
}

void rm_right(){
  upd(a[me], -1);
  ans -= query(a[me], 1);
}


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  read();
  mb = 0, me = -1;
  for(int i = 0; i < q; ++i){
    curr = queries[i].ff;
    while(me < curr.ss){
      ++me;
      add_right();
    }

    while(me > curr.ss){
      rm_right();
      --me;
    }

    while(mb < curr.ff){
      rm_left();
      ++mb;
    }

    while(mb > curr.ff){
      --mb;
      add_left();
    }

    pr[queries[i].ss] = ans;
  }


  for(int i = 0; i < q; ++i)  cout << pr[i] << "\n";
  return 0;
}
