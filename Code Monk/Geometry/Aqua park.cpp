#include <bits/stdc++.h>

using namespace std;
typedef pair<double, int> pii;
typedef tuple<int, int, int, int> tii;

vector <tii> segments;
set<pii> heights[10100];

int main(){
  ios_base::sync_with_stdio(0);
  int n, x;
  auto aup = heights[0].begin();
  double auh, y, aux1, aux2, auy1, auy2;
  cin >> x >> n;
  y = 10010.0;
  for(int i = 0; i < n; ++i){
    cin >> aux1 >> auy1 >> aux2 >> auy2;
    segments.push_back(tii(aux1, aux2, auy1, auy2));
    for(int j = min(aux1, aux2); j <= max(aux1, aux2); ++j){
      auh = (auy2 - auy1)*j;
      auh += auy1*aux2 - auy2*aux1;
      auh = (auh)/(aux2 - aux1);
      heights[j].insert(pii(auh, i));
    }
  }
  //for(auto i : heights[14])  cout << i.first  << " " << i.second << endl;
  while(1){
    //cin >> aux1;
    //cout << x << " ";
    aup = heights[x].upper_bound(pii(y, -1));
    if(aup == heights[x].begin()) break;
    --aup;
    //cout << aup -> second << endl;
    if(get<2>(segments[aup -> second]) < get<3>(segments[aup -> second])) x = get<0>(segments[aup -> second]);
    else  x = get<1>(segments[aup -> second]);
    y = min(get<2>(segments[aup -> second]) , get<3>(segments[aup -> second]));
    cout << x << " " << y << "\n";
    //  --y;
  }
  //cout << endl;
  cout << x << "\n";


  return 0;
}
