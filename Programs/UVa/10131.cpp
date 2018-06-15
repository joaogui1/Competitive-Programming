#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> iii;

vector <iii> e;
vector <int> an;

int dp[1 << 10], pai[1 << 10];

int main(){
  int aux, auy, ans = 0, cont = 1;
  while(scanf("%d %d", &aux, &auy) != EOF){
      e.push_back(iii(pii(-auy, aux), cont));
      ++cont;
  }
  memset(pai, -1, sizeof pai);
  sort(e.begin(), e.end());
  for(int i = 0; i < e.size(); ++i) dp[i] = 1;


  for(int i = 0; i < e.size(); ++i)
    for(int j = 0; j < i; ++j)
      if(e[i].first.second > e[j].first.second && e[i].first.first > e[j].first.first && dp[i] < dp[j] + 1){
        dp[i] = dp[j] + 1;
        pai[i] = j;
      }

  for(int i = 0; i < e.size(); ++i)
    if(dp[i] > dp[ans]) ans = i;
  printf("%d\n", dp[ans]);

  for(; ans != -1; ans = pai[ans])  an.push_back(e[ans].second);
  for(int i = an.size() - 1; i > -1; --i) printf("%d\n", an[i]);

  return 0;
}
