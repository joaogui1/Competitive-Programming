#include <bits/stdc++.h>

using namespace std;

int main(){
  bool test = 0;
  int n, m, a, l = -1;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i){
    test = 1;
    for(int j = 0; j < m; ++j){
      scanf("%d", &a);
      if(j <= l && a != 0){
        printf("N\n");
        return 0;
      }
      if(a != 0 && test){
        l = j;
        test = 0;
      }
    }
    if(test == 1)  l = m;
  }
  printf("S\n");

  return 0;
}
