#include <bits/stdc++.h>

using namespace std;

string dict[1024];

int comp(int a, int b){
  int ret = 0;
  for(int i = 0; i < dict[a].size(); ++i)
    ret += (dict[a][i] != dict[b][i]);
  return ret;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> dict[i];
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(i != j)
        if(comp(i, j) > 1)  break;
      if(j == n - 1){
        cout << dict[i] << "\n";
        return 0;
      }
    }
  }

  return 0;
}
