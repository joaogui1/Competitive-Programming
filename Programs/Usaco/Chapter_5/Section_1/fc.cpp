/*
ID: joaogui1
LANG: C++
TASK: fc
*/
#include <bits/stdc++.h>
#define x real()
#define y imag()
#define eps 0.0000001
#define pb push_back

using namespace std;
typedef complex <double> point;

point pivot;
vector <point> p, hull;

bool comp(point a, point b){
  if(abs(arg(a - pivot) - arg(b - pivot)) < eps) return abs(a - pivot) < abs(b - pivot);
  return arg(a - pivot) < arg(b - pivot);
}

double cross(point a, point b){
  return (conj(a)*b).y;
}

bool ccw(point a, point b){
  //if(abs(cross(a, b)) < eps) return abs(a) > abs(b);
  return cross(a, b) < 0;
}

bool ccw(point a, point b, point c){
  return ccw(b - a, c - a);
}

int main(){
  ios_base::sync_with_stdio(0);
  ifstream fin ("fc.in");
  ofstream fout ("fc.out");
  int n, pos = 0;
  double px, py, ans = 0;
  fin >> n;
  for(int i = 0; i < n; ++i){
    fin >> px >> py;
    p.pb(point(px, py));
  }

  for(int i = 1; i < n; ++i)
    if(p[i].y < p[pos].y  || (abs(p[i].y - p[pos].y) < eps && p[i].x < p[pos].x))
        pos = i;
  swap(p[pos], p[0]);
  pivot = p[0];
  sort(++p.begin(), p.end(), comp);

  for(int i = 0; i < n; ++i){
    //if(i > 0 && p[i] == p[i - 1]) continue;
    while(hull.size() >= 2 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], p[i])) hull.pop_back();
    hull.push_back(p[i]);
  }
  hull.push_back(p[0]);
  for(int i = 0; i < hull.size() - 1; ++i)
    ans += abs(hull[i] - hull[i + 1]);
  fout << fixed << setprecision(2) << ans << "\n";

  return 0;
}
