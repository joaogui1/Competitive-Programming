#include <bits/stdc++.h>
#define x first
#define y second
#define eps 0.00001

using namespace std;
typedef pair<double, double> pdd;
typedef pair<pdd, pdd> ppd;

struct comp{
  bool operator()(const pdd &a, const pdd &b) const{
    return pdd(a.y, a.x) < pdd(b.y, b.x);
  }
};

vector <pdd> points;
set <pdd, comp> s;

double dist(pdd a, pdd b){
  return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}


void initialize(){
  s.clear();
  points.clear();
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, last = 0;
  pdd a;
  ppd ans;
  double h;
  set<pdd>::iterator it;
  while(1){
    last = 0;
    cin >> n;
    if(n == 0)  return 0;
    initialize();
    h = (1 << 20) + 0.5;
    for(int i = 0; i < n; ++i){
      cin >> a.x >> a.y;
      points.push_back(a);
    }
    sort(points.begin(), points.end());
    ans = ppd(points[0], points[1]);

    s.insert(points[0]);
    //for(int i = 0; i < n; ++i)  s.insert(points[i]);
    //for(;s.size(); s.erase(s.begin()))
      //cout << s.begin()->x << " " << s.begin()->y << "\n";
    for(int i = 1; i < n; ++i){
      while(last < i && points[i].x - points[last].x > h)
        s.erase(points[last++]);
      it = s.lower_bound(pdd(0, points[i].y - h));
      for(; it != s.end() && it->y < points[i].y + h; ++it){
        if(h > dist(points[i], *it)){
          h = dist(points[i], *it);
          ans = ppd((*it), points[i]);
        }
      }

      s.insert(points[i]);
    }

    cout << fixed << setprecision(2) << ans.x.x << " " << ans.x.y << " " << ans.y.x << " " << ans.y.y << "\n";
  }


  return 0;
}
