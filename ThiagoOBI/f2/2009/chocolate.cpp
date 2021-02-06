#include <bits/stdc++.h>

using namespace std;

int n, m, cnt[1001100], mov[1001100];
bool f(){
  for(int i = 0; i <= n; ++i){
    if(cnt[i] == 0)
      for(int j = 1; j <= m; ++j)
          ++cnt[i + j], mov[i + j] = j;

    else if(cnt[i] == 1)
      ++cnt[i + mov[i]], mov[i + mov[i]] = mov[i];

  }
  return (cnt[n] > 0);
}

int main(){
  scanf("%d %d", &n, &m);

  printf("%s\n", f()?"Paula":"Carlos");

  return 0;
}
