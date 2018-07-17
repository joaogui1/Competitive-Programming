#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <double, double> pdd;
typedef pair <pdd, pdd> ppd;
typedef pair <ppd, pdd> ppp;
typedef pair <ppp, char> fig;

fig arr[16];

double dist(pdd a, pdd b){
  return sqrt((a.ff - b.ff)*(a.ff - b.ff) + (a.ss - b.ss)*(a.ss - b.ss));
}

double cross(pdd a, pdd b){
  return (a.ff*b.ss - a.ss*b.ff);
}

pdd _minus(pdd a, pdd b){
  return pdd(a.ff - b.ff, a.ss - b.ss);
}

pdd _sum(pdd a, pdd b){
  return _minus(a, pdd(-b.ff, -b.ss));
}

bool side(ppd line, pdd c, pdd d){
  pdd ca = _minus(c, line.ff);
  pdd da = _minus(d, line.ff);
  pdd ba = _minus(line.ss, line.ff);
  double x = cross(ba, ca), y = cross(ba, da);
  return (x*y > 0.00001);
}

bool inside(ppp trig, pdd a){
  pdd b = _sum(trig.ss, _sum(trig.ff.ff, trig.ff.ss));
  b.ff /= 3.0, b.ss /= 3.0;
  return (side(trig.ff, a, b) && side(ppd(trig.ff.ff, trig.ss), a, b) && side(ppd(trig.ff.ss, trig.ss), a, b));
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
      cin >> arr[t].ff.ff.ff.ff >> arr[t].ff.ff.ff.ss >> arr[t].ff.ff.ss.ff >> arr[t].ff.ff.ss.ss;

    else if(op == 'c')
      cin >> arr[t].ff.ff.ff.ff >> arr[t].ff.ff.ff.ss >> arr[t].ff.ff.ss.ff;

    else
      cin >> arr[t].ff.ff.ff.ff >> arr[t].ff.ff.ff.ss >> arr[t].ff.ff.ss.ff >> arr[t].ff.ff.ss.ss >> arr[t].ff.ss.ff >> arr[t].ff.ss.ss;

    cin >> op;
  }

  cin >> points.ff >> points.ss;
  for(int i = 1; points.ff != 9999.9 || points.ss != 9999.9; ++i){
    vdc = 0;
    for(int j = 1; j < t; ++j){
      if(arr[j].ss == 'r'){
        if(points.ff > arr[j].ff.ff.ff.ff && points.ss < arr[j].ff.ff.ff.ss && points.ff < arr[j].ff.ff.ss.ff && points.ss > arr[j].ff.ff.ss.ss){
          vdc = 1;
          cout << "Point "<< i <<" is contained in figure " << j << "\n";
        }
      }

      else if(arr[j].ss == 'c'){
        if(dist(points, arr[j].ff.ff.ff) < arr[j].ff.ff.ss.ff){
          vdc = 1;
          cout << "Point "<< i <<" is contained in figure " << j << "\n";
        }
      }

      else{
        if(inside(arr[j].ff, points)){
          vdc = 1;
          cout << "Point "<< i <<" is contained in figure " << j << "\n";
        }
      }


    }
    if(!vdc) cout << "Point " << i <<" is not contained in any figure\n";
    cin >> points.ff >> points.ss;
  }



  return 0;
}
