#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <double, double> pdd;
typedef pair <pdd, pdd> ppd;

int main(){
  ios_base::sync_with_stdio(0);

  int t;
  char op;
  bool vdc;
  ppd arr[16];
  pdd points;

  cin >> op;
  for(t = 1; op != '*'; ++t){
    cin >> arr[t].ss.ff >> arr[t].ff.ss >> arr[t].ff.ff >> arr[t].ss.ss;
    cin >> op;
  }

  cin >> points.first >> points.second;
  for(int i = 1; (fabs(points.first - 9999.9) > 0.000001 || fabs(points.second - 9999.9) > 0.000001); ++i){
    vdc = 0;
    for(int j = 1; j < t; ++j){
      if(points.ff < arr[j].ff.ff && points.ss < arr[j].ff.ss && points.ff > arr[j].ss.ff && points.ss > arr[j].ss.ss){
        vdc = 1;
        cout << "Point "<< i <<" is contained in figure " << j << "\n";
      }
    }
    if(!vdc)  cout << "Point "<< i <<" is not contained in any figure\n";
    cin >> points.first >> points.second;
  }

  return 0;
}
