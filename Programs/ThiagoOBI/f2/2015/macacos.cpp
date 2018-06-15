#include <bits/stdc++.h>
#define y imag()
#define x real()
#define eps 0.0000001

using namespace std;
typedef complex<double> point;

vector <point> p, hull;

double cross(point a, point b){
  return (conj(a)*b).y;
}

bool ccw(point a, point b){
  return cross(a, b) <= 0;
}

bool ccw(point a, point b, point c){
  return ccw(a - b, c - b);
}

bool comp(point a, point b){
  if(a.x == b.x)  return a.y < b.y;
  return a.x < b.x;
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, aux, auy;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> aux >> auy;
    p.push_back(point(aux, auy));
  }

  sort(p.begin(), p.end(), comp);
  for(int i = 0; i < n; ++i){
    while(hull.size() > 1 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], p[i])) hull.pop_back();
    hull.push_back(p[i]);
  }


  cout << hull.size() - 1 << "\n";
  return 0;
}
