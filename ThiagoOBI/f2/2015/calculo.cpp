#include <bits/stdc++.h>

using namespace std;

int a[1024], b[1024], c[1024];
int main(){
  int n, m, aux = 0;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i)  scanf("%d", &a[i]);
  for(int i = 1; i <= m; ++i)  scanf("%d", &b[i]);
  for(int i = max(n, m); i > 0; --i){
    c[i] = (a[i] + b[i] + aux)%2;
    aux = (a[i] + b[i] + aux)/2;
  }
  aux = 0;
  for(int i = 1; i <= max(n, m); ++i)
    if(c[i] != 0) aux = i;

  for(int i = 1; i <= aux; ++i)
    printf("%d%s", c[i], (i == aux)?"\n":" ");

  return 0;
}
