#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;

vector <ppi> v;
int main(){
  int n, m, o, p, b;
  scanf("%d %d", &n, &m);

  for(int i = 1; i <= n; ++i)
    v.push_back(ppi(pii(0, 0), pii(0, -i)));
  for(int i = 0; i < m; ++i){
    scanf("%d %d %d", &o, &p, &b);
    ++v[o - 1].ff.ff, ++v[p - 1].ff.ss, ++v[b - 1].ss.ff;
  }

  sort(v.rbegin(), v.rend());

  for(int i = 0; i < v.size(); ++i)
    printf("%d%s", -v[i].ss.ss, (i + 1 == v.size())?"\n":" ");
  return 0;
}
