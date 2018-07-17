#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int lli;
typedef pair<lli, lli> pll;

int main(){
  char op;
  int ans = 0;
  lli n, m, add;
  pll pos = pll(0, 0);
  scanf("%lld %lld", &n, &m);
  for(int i = 0; i < n; ++i){
    scanf(" %c %lld", &op, & add);
    if(op == 'N') pos.ss += add;
    else if(op == 'S')  pos.ss -= add;
    else if(op == 'L')  pos.ff += add;
    else if(op == 'O')  pos.ff -= add;

    if(pos.ff*pos.ff + pos.ss*pos.ss > m*m) ans = 1;
  }
  printf("%d\n", ans);

  return 0;
}
