#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

vector <pii> points;

int ccw(pii a, pii b){
  return (a.ff*b.ss - a.ss*b.ff < 0);
}

int ccw(pii a, pii b, pii c){
  return ccw(pii(a.ff - b.ff, a.ss - b.ss), pii(c.ff - b.ff, c.ss - b.ss));
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, ans = 0;
  pii aup;
  cin >> n;
  for(int i = 0; i < n + 1; ++i){
    cin >> aup.ff >> aup.ss;
    points.push_back(aup);
  }
  for(int i = 1; i < (int)points.size() - 1; ++i)
    if(ccw(points[i - 1], points[i], points[i + 1]))  ++ans;
  cout << ans << "\n";

  return 0;
}
