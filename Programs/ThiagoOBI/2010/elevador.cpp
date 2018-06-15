#include <bits/stdc++.h>

using namespace std;

int main(){
  char ans[2] = {'N', 'S'};
  int n, c, s, e, sum = 0, vdc = 0;
  scanf("%d %d", &n, &c);
  for(int i = 0; i < n; ++i){
    scanf("%d %d", &s, &e);
    sum += e - s;
    vdc |= (sum > c);
  }

  printf("%c\n", ans[vdc]);

  return 0;
}
