#include <bits/stdc++.h>

using namespace std;

int p[50010], n;

int find(int x){
  return (p[x] == x)?x:(p[x] = find(p[x]));
}

void join(int x, int y){
  --n;
  p[find(x)] = find(y);
}

int main(){
  int m, u, v;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i) p[i] = i;
  for(int i = 0; i < m; ++i){
    scanf("%d %d", &u, &v);
    if(find(u) != find(v))  join(u, v);
  }
  printf("%d\n", n);

  return 0;
}
