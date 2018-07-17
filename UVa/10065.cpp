#include <bits/stdc++.h>
#define x real()
#define y imag()
#define eps 0.000001

using namespace std;
typedef complex <double> point;

double shoe(vector <point> p){
  double ret = 0;
  for(int i = 0; i < p.size() - 1; ++i) ret += p[i].x*p[i + 1].y;
  ret += p[p.size() - 1].x*p[0].y;
  for(int i = 0; i < p.size() - 1; ++i) ret-= p[i + 1].x*p[i].y;
  ret -= p[0].x*p[p.size() - 1].y;
  return abs(ret)/2.0;
}
point pivot;
vector <point> p, po, hull;

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

bool angcomp(point a, point b){
  if(abs(cross(a - pivot, b - pivot)) < eps)  return abs(a - pivot) < abs(b - pivot);
  return arg(a - pivot) < arg(b - pivot);
}

void initialize(){
    p.clear();
    po.clear();
    hull.clear();
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, cont, pos;
  double aux, auy, ans;
  for(int t = 1; ; ++t){
    pos = 0;
    cin >> n;
    initialize();
    if(n == 0)  return 0;
    for(int i = 0; i < n; ++i){
      cin >> aux >> auy;
      p.push_back(point(aux, auy));
      po.push_back(p[i]);
    }

    for(int i = 1; i < n; ++i)
      if(p[i].y < p[pos].y  || (abs(p[i].x - p[pos].x) < eps && p[i].x > p[pos].x))
        pos = i;
    swap(p[pos], p[0]);
    pivot = p[0];
    sort(++p.begin(), p.end(), angcomp);
    hull.push_back(p[p.size() - 1]);
    hull.push_back(p[0]);
    hull.push_back(p[1]);
    cont = 2;
    while(cont < n){
      if(ccw(hull[hull.size() - 2], hull[hull.size() - 1], p[cont]))  hull.push_back(p[cont++]);
      else  hull.pop_back();
    }
    hull.pop_back();

    //for(int i = 0; i < hull.size(); ++i)
      //cout << hull[i] << " \n"[i == hull.size() - 1];
    ans = 1 - shoe(po)/shoe(hull);
    ans *= 100;
    //if(t != 1)  cout << "\n";
    cout << "Tile #" << t << "\n";
    cout << "Wasted Space = " << fixed << setprecision(2) << ans << " %\n\n";

  }





  return 0;
}
