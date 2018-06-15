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
  double aux, auy, r;
  cin >> t;
  while(t--){
    best = -1;
    cin >> n >> r;
    r /= 2.0;
    mosq.clear();
    for(int i = 0; i < n; ++i){
      cin >> aux >> auy;
      mosq.push_back(point(aux, auy));
    }

    for(point a: mosq)
      for(point b: mosq){
        
      }
    cout << best << "\n";
  }

  return 0;
}
