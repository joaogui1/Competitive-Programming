#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

pii mov[8] = {pii(1, 2), pii(2, 1), pii(2, -1), pii(1, -2), pii(-1, -2), pii(-2, -1), pii(-2, 1), pii(-1, 2)};

int main(){
  pii pos;
  int n, op;
  scanf("%d", &n);
  pos.ff = 4, pos.ss = 3;
  for(int i = 1; i <= n; ++i){
    scanf("%d", &op);
    --op;
    pos.ff += mov[op].ff;
    pos.ss += mov[op].ss;
    if((pos == pii(1, 3)) || (pos == pii(2, 3)) || (pos == pii(2, 5)) || (pos == pii(5, 4)) || (i == n)){
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}
