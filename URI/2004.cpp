#include <bits/stdc++.h>

using namespace std;

int v[110];
int main(){
  int t, n, aux, auy, ans;
  scanf("%d", &t);

  while(t--){
    scanf("%d", &n);
    ans = 0;
    memset(v, 0, sizeof v);
    for(int i = 0; i < n; ++i){
      scanf("%d %d", &aux, &auy);
      if(v[aux] == 0 || (v[aux] > 100 && (auy <= 100 && auy >= 10)) || (v[aux] < 10 && (auy <= 100 && auy >= 10))) v[aux] = auy;
      else if((v[aux] > 100 || v[aux] < 10) && (auy > 100 || auy < 10)) v[aux] = max(v[aux], auy);
      else if((v[aux] <= 100 && v[aux] >= 10) &&  (auy <= 100 && auy >= 10))  v[aux] = max(v[aux], auy);
    }

    for(int i = 1; i < 101; ++i)
      if(v[i] != 0) ans += v[i];

    printf("%d\n", ans);
  }


  return 0;
}
