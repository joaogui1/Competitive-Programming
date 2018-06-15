#include <bits/stdc++.h>

using namespace std;
typedef pair<int, string> pis;

vector <pis> regions[10010];

int main(){
  ios_base::sync_with_stdio(0);
  int n, m, r, p;
  string in;
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    cin >> in >> r >> p;
    regions[r].push_back(pis(p, in));
  }
  for(int i = 1; i <= m; ++i) sort(regions[i].rbegin(), regions[i].rend());
  for(int i = 1; i <= m; ++i){
    if(regions[i].size() == 2) cout << regions[i][0].second << " " << regions[i][1].second << "\n";
    else{
      //cout << regions[i][0].first << " " << regions[i][2].first << endl;
      if(regions[i][1].first == regions[i][2].first)  cout << "?\n";
      else  cout << regions[i][0].second << " " << regions[i][1].second << "\n";
    }
  }

  return 0;
}
