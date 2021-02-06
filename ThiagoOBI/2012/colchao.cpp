#include <bits/stdc++.h>

using namespace std;

int main(){
  int c[4], p[2];
  scanf("%d %d %d %d %d", &c[0], &c[1], &c[2], &p[0], &p[1]);
  sort(c, c + 3);
  sort(p, p + 2);
  if(c[0] <= p[0] && c[1] <= p[1])  printf("S\n");
  else  printf("N\n");


  return 0;
}
