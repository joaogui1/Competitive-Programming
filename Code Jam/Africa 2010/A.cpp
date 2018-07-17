#include <bits/stdc++.h>

using namespace std;

vector <int> p[1 << 10];

int main(){
  ios_base::sync_with_stdio(0);
  int n, c, m, aux;
  cin >> n;
  for(int q = 1; q <= n; ++q){
    cin >> c >> m;
    for(int i = 0; i < (1 << 10); ++i)  p[i].clear();
    for(int i = 0; i < m; ++i){
      cin >> aux;
      p[aux].push_back(i + 1);
    }

    cout << "Case #" << q << ": ";
    for(int i = 0; i < (1 << 10); ++i){
      for(int j = 0; j < p[i].size(); ++j){
        if(2*i != c && p[c - i].size()){
          cout << min(p[i][0], p[c - i][0]) << " " << max(p[i][0], p[c - i][0]) << "\n";
          i = (1 << 10);
          break;
        }
        else if(2*i == c && p[i].size() == 2){
          cout << p[i][0] << " " << p[i][1] << "\n";
          i = (1 << 10);
          break;
        }
      }
    }

  }


  return 0;
}
