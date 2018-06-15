#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector<ll> sum[2];
ll a[4][4112], ans;

int main(){
  int n, beg = 0, fim = 0;
  scanf("%d", &n);
  for(int j = 0; j < n; ++j)
    for(int i = 0;  i < 4; ++i)
      scanf("%lld", &a[i][j]);
  for(int k = 0; k < 2; ++k)
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        sum[k].push_back((1 - 2*k)*(a[2*k][i] + a[2*k + 1][j]));

  sort(sum[0].begin(), sum[0].end());
  sort(sum[1].begin(), sum[1].end());

  for(int i = 0; i < sum[0].size(); ++i){
    for(; sum[1][beg] < sum[0][i] && beg < sum[1].size(); ++beg);
    for(; sum[1][fim] <= sum[0][i] && fim < sum[1].size(); ++fim);
    ans += fim - beg;
  }

  printf("%lld\n", ans);


  return 0;
}
