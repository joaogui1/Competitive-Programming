#include <bits/stdc++.h>
#define ff first
#define ss second
#define eps 0.00000001

using namespace std;
typedef pair<double, double> pdd;

pdd a, b, t;
vector <pdd> va, vb;

double dist(pdd a, pdd b){
  return sqrt((a.ff - b.ff)*(a.ff - b.ff) + (a.ss - b.ss)*(a.ss - b.ss));
}

bool compa(pdd x, pdd y){
  return dist(x, a) - dist(x, t) < dist(y, a) - dist(y, t);
}

bool compb(pdd x, pdd y){
  return dist(x, b) - dist(x, t) < dist(y, b) - dist(y, t);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  double ax, ay, f, fa, fb, ans = 0, best = 0;
  pdd pa, pb;
  cin >> ax >> ay;
  a = pdd(ax, ay);
  cin >> ax >> ay;
  b = pdd(ax, ay);
  cin >> ax >> ay;
  t = pdd(ax, ay);
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> ax >> ay;
    va.push_back(pdd(ax, ay));
    vb.push_back(va[i]);
  }

  sort(va.begin(), va.end(), compa);
  sort(vb.begin(), vb.end(), compb);

  if(va.size() == 1)  ans += min(dist(va[0], a), dist(vb[0], b)) + dist(t, va[0]);
  else{
    for(int i = 0; i < n; ++i)  ans += 2*dist(t, va[i]);
    best = dist(va[0], a) - dist(t, va[0]);
    best = min(best, dist(vb[0], b) - dist(t, vb[0]));
    best = min(best, dist(va[0], a) - dist(t, va[0]) + dist(vb[1], b) - dist(t, vb[1]));
    best = min(best, dist(va[1], a) - dist(t, va[1]) + dist(vb[0], b) - dist(t, vb[0]));
    if(va[0] != vb[0])
      best = min(best, dist(va[0], a) - dist(t, va[0]) + dist(vb[0], b) - dist(t, vb[0]));
  }

  //cout << pa.ff << " " << pa.ss << " " << pb.ff << " " << pb.ss << endl;
  cout << fixed << setprecision(12) << ans + best << "\n";

  return 0;

}
