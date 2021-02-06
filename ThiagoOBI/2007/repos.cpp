#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <int, int> pii;

set <pii> ans;
map <int, int> pr;

int main(){
  int n, c, p, v;
  set<pii>::iterator itx;
  scanf("%d %d", &n, &c);
  for(int i = 0; i < n; ++i){
    scanf("%d %d", &p, &v);
    pr[p] = v;
  }
  for(int i = 0; i < c; ++i){
    scanf("%d %d", &p, &v);
    if(pr.count(p) == 0)  ans.insert(pii(p, v));
    else if(pr[p] < v)  ans.insert(pii(p, v));
  }
  for(set<pii>::iterator it = ans.begin(); it != ans.end(); ++it){
    itx = it;
    ++itx;
    if(itx == ans.end() || it->ff != itx->ff)
      printf("%d %d\n", it -> ff, it -> ss);
  }

  return 0;
}
