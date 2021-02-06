#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <double, double> pdd;
typedef pair <pdd, pdd> ppd;
typedef pair <ppd, char> fig;

fig arr[16];

double dist(pdd a, pdd b){
  return sqrt((a.ff - b.ff)*(a.ff - b.ff) + (a.ss - b.ss)*(a.ss - b.ss));
}

int main(){
  ios_base::sync_with_stdio(0);
  int t;
  char op;
  bool vdc;
  pdd points;
  cin >> op;
  for(t = 1; op != '*'; ++t){
    arr[t].ss = op;
    if(op == 'r')
      cin >> arr[t].ff.ff.ff >> arr[t].ff.ff.ss >> arr[t].ff.ss.ff >> arr[t].ff.ss.ss;

    else
      cin >> arr[t].ff.ff.ff >> arr[t].ff.ff.ss >> arr[t].ff.ss.ff;

    cin >> op;
  }

  cin >> points.ff >> points.ss;
  for(int i = 1; points.ff != 9999.9 || points.ss != 9999.9; ++i){
    vdc = 0;
    for(int j = 1; j < t; ++j){
      if(arr[j].ss == 'r'){
        if(points.ff > arr[j].ff.ff.ff && points.ss < arr[j].ff.ff.ss && points.ff < arr[j].ff.ss.ff && points.ss > arr[j].ff.ss.ss){
          vdc = 1;
          cout << "Point "<< i <<" is contained in figure " << j << "\n";
        }
      }
      else
        if(dist(points, arr[j].ff.ff) < arr[j].ff.ss.ff){
          vdc = 1;
          cout << "Point "<< i <<" is contained in figure " << j << "\n";
        }

    }
    if(!vdc) cout << "Point " << i <<" is not contained in any figure\n";
    cin >> points.ff >> points.ss;
  }



  return 0;
}
