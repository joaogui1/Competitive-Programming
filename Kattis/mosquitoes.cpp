#include <bits/stdc++.h>
#define x real()
#define y imag()
#define PI 3.1415926535


using namespace std;
typedef complex <double> point;

vector <point> mosq;

int main(){
  ios_base::sync_with_stdio(0);
  int n, t, best, test;
  point centre;
  double aux, auy, r, minx, miny, maxx, maxy;
  cin >> t;
  while(t--){
    best = -1;
    maxx = maxy = -101;
    minx = miny = 101;
    cin >> n >> r;
    r /= 2.0;
    mosq.clear();
    for(int i = 0; i < n; ++i){
      cin >> aux >> auy;
      mosq.push_back(point(aux, auy));
      minx = min(minx, aux);
      miny = min(miny, auy);
      maxx = max(maxx, aux);
      maxy = max(maxy, auy);
    }

    for(point ce: mosq)
      for(double ang = 0; ang < 2*PI + 1; ang += PI/1024){
        test = 0;
        centre = ce + polar(r, ang);
        for(const point & m: mosq){
          if(abs(centre - m) <= r + 0.00001)
            ++test;
          }
        best = max(best, test);
      }
    cout << best << "\n";
  }

  return 0;
}
