#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

vector <pii> v;

int main(){
  int n, m, a;
  scanf("%d %d", &n, &m);
  v.assign(n, pii(0, 0));
  for(int i = 1; i < n; ++i)  scanf("%d", &v[i].ff);
  for(int i = 0; i < n; ++i)  scanf("%d", &v[i].ss);
  for(int i = 0; i < m; ++i){
    scanf("%d", &a);
    printf("%d%s", (--upper_bound(v.begin(), v.end(), pii(a, (1 << 30))))->ss, (i == m - 1)?"\n":" ");
  }


  return 0;
}
