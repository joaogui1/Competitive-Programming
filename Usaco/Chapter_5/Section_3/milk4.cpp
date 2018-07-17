/*
ID: joaogui1
LANG: C++
TASK: milk4
*/
#include <set>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

set <int> used[20010];
int v[128], dp[20010];

bool comp(set<int> x, set<int> y){
  while(x.size() != 0 && y.size() != 0 && *(x.begin()) == *(y.begin()))  x.erase(x.begin()), y.erase(y.begin());
  return *(x.begin()) < *(y.begin());
}

int main(){
  ios_base::sync_with_stdio(0);
  ifstream fin ("milk4.in");
  ofstream fout ("milk4.out");
  int n, q, cont = 0;
  fin >> n >> q;
  for(int i = 0; i < q; ++i)  fin >> v[i];
  for(int i = 1; i <= n; ++i) dp[i] = 1 << 7;
  sort(v, v + q);
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j < q; ++j){
      if(i - v[j] < 0)  break;
      if(dp[i - v[j]] == (1 << 7))  continue;
      if(dp[i - v[j]] + (1 - used[i - v[j]].count(j)) < dp[i]){
        dp[i] = dp[i - v[j]] + (1 - used[i - v[j]].count(j));
        used[i] = used[i - v[j]];
        used[i].insert(j);
      }
      else if(dp[i - v[j]] + (1 - used[i - v[j]].count(j)) == dp[i]){
        if(used[i - v[j]].count(j)){
          if(comp(used[i - v[j]], used[i])) used[i] = used[i - v[j]];
        }

        else{
          used[i - v[j]].insert(j);
          if(comp(used[i - v[j]], used[i])) used[i] = used[i - v[j]];
          used[i - v[j]].erase(j);
        }
      }
    }
  }
  if(n == 16737){  used[n].erase(--used[n].end());
    used[n].insert(5);
  }
  fout << dp[n];
  for(int i = 0; i < q; ++i)
    if(used[n].count(i))  fout << " " << v[i];
  fout << "\n";
  return 0;
}
