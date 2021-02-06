#include <complex>
#include <iostream>
#define y imag()
#define x real()
#define eps 0.00000001

using namespace std;
typedef complex<double> point;
typedef pair<point, point> ppp;

vector<point> in, out;

double cross(point a, point b, point c){
  point ab = b - a;
  point ac = c - a;
  return (conj(ab)*ac).y;
}

double dot(point a, point b, point c){
  point ab = b - a;
  point ac = c - a;
  return (conj(ab)*ac).x;
}

double dist(point a, ppp b){
  double ret = cross(b.first, b.second, a)/abs(b.first - c.first);
  double dot1 = dot(b.first, b.second, a);
}

double dist(ppp a, ppp b){
  double ret = 100000000000;
  ret
}

int main(){
  ios_base::sync_with_stdio(0);
  int no, ni, t;
  double aux, auy, ans;
  cin >> t;
  while(t--){
    cin >> ni >> no;
    ans = (1 << 20);
    in.clear();
    out.clear();
    for(int i = 0; i < ni; ++i){
      cin >> aux >> auy;
      in.push_back(point(aux, auy));
    }
    for(int i = 0; i < no; ++i){
      cin >> aux >> auy;
      out.push_back(point(aux, auy));
    }
    in.push_back(in[0]);
    out.push_back(out[0]);

    for(int i = 0; i < ni; ++i)
      for(int j = 0; j < no; ++j)
        ans = min(ans, abs(in[i] - out[j]));

    for(int i = 0; i < ni; ++i)
      for(int j = 0; j < no; ++j)
        ans = min(ans, dist())

  }
}
