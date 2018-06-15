#include <bits/stdc++.h>
#define y imag()
#define x real()
#define eps 0.00001
#define pi 3.1415926535

using namespace std;
typedef complex<double> point;

double cross(point a, point b){
  return (conj(a)*b).y;
}

bool ccw(point a, point b){
  if(abs(cross(a, b)) < eps) return abs(a) < abs(b);
  return cross(a, b) > 0;
}

bool ccw(point a, point b, point c){
  return ccw(b - a, c - a);
}

double shoe(vector <point> &p){
  double ret = 0;
  p.push_back(p[0]);
  for(int i = 0; i < p.size() - 1; ++i) ret += cross(p[i], p[i + 1]);
  p.pop_back();
  return abs(ret)/2;
}
point pivot;
vector<point> p, hull;

bool comp(point a, point b){
  if(abs(arg(a - pivot) - arg(b - pivot)) < eps)  return arg(a - pivot) < arg(b - pivot);
  return arg(a - pivot) < arg(b - pivot);
}

void initialize(){
  p.clear();
  hull.clear();
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, c, pos, cont;
  point aup, mov[2];
  double aux, auy, w, h, v, area, ans;
  cin >> c;
  for(int t = 1; t <= c; ++t){
    pos = 0;
    cont = 2;
    cin >> n;
    area = 0.0;
    initialize();
    for(int i = 0; i < n; ++i){
      cin >> aux >> auy >> w >> h >> v;

      area += h*w;
      v *= pi/180.0;
      mov[0] = point(sin(v)*h/2.0, cos(v)*h/2.0);
      v += pi/2;
      mov[1] = point(sin(v)*w/2.0, + cos(v)*w/2.0);

      p.push_back(point(aux, auy) + mov[0] + mov[1]);
      p.push_back(point(aux, auy) - mov[0] + mov[1]);
      p.push_back(point(aux, auy) + mov[0] - mov[1]);
      p.push_back(point(aux, auy) - mov[0] - mov[1]);
    }

    for(int i = 0; i < p.size(); ++i)
      cout << p[i] << " \n"[i%4 == 3];

    for(int i = 1; i < n; ++i)
      if(p[i].y < p[pos].y  || (abs(p[i].y - p[pos].y) < eps && p[i].x > p[pos].x))
        pos = i;
    swap(p[pos], p[0]);
    pivot = p[0];
    sort(++p.begin(), p.end(), comp);
    hull.push_back(p[p.size() - 1]);
    hull.push_back(p[0]);
    hull.push_back(p[1]);
    cont = 2;
    while(cont < n){
      if(ccw(hull[hull.size() - 2], hull[hull.size() - 1], p[cont]))  hull.push_back(p[cont++]);
      else  hull.pop_back();
    }
    hull.pop_back();

    ans = area/shoe(hull);
    ans *= 100;

    cout << area << " " << shoe(hull) << " " << fixed << setprecision(1) << ans << " %\n";

  }



  return 0;
}
