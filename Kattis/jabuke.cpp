#include <bits/stdc++.h>
#define x real()
#define y imag()


using namespace std;
typedef complex <double> point;

point trig[8];

double area(point a, point b, point c){
  return 0.5*abs((conj(b - a)*(c - a)).y);
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, ans = 0;
  double aux, auy, aua, ar_trig;
  for(int i = 0; i < 3; ++i){
    cin >> aux >> auy;
    trig[i] = point(aux, auy);
  }
  ar_trig = area(trig[0], trig[1], trig[2]);
  cout << fixed << setprecision(1) << ar_trig << "\n";

  cin >> n;

  while(n--){
    cin >> aux >> auy;
    trig[3] = point(aux, auy);
    aua = area(trig[0], trig[1], trig[3]) + area(trig[0], trig[2], trig[3]) + area(trig[2], trig[1], trig[3]);
    if(abs(aua - ar_trig) < 0.000001) ++ans;
  }
  cout << ans << "\n";

  return 0;
}
