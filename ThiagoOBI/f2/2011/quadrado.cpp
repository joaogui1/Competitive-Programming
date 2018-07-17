#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll mk[1 << 20], g[1024][1024];

int main(){
  ll n, sum = 0, test;
  scanf("%lld", &n);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      scanf("%lld", &g[i][j]), ++mk[g[i][j]];
  for(int i = 1; i <= n*n; ++i)
    if(mk[i] == 0){
      printf("0\n");
      return 0;
    }
  for(int i = 0; i < n; ++i)  sum += g[0][i];
  for(int i = 1; i < n; ++i){
    test = 0;
    for(int j = 0; j < n; ++j)  test += g[i][j];
    if(sum != test){
      printf("0\n");
      return 0;
    }
  }
  for(int i = 0; i < n; ++i){
    test = 0;
    for(int j = 0; j < n; ++j)  test += g[j][i];
    if(sum != test){
      printf("0\n");
      return 0;
    }
  }
  test = 0;
  for(int i = 0; i < n; ++i)  test += g[i][i];
  if(sum != test){
    printf("0\n");
    return 0;
  }

  printf("%lld\n", sum);
  return 0;
}
