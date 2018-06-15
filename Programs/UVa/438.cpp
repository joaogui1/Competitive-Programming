#include <bits/stdc++.h>
#define ff first
#define ss second
#define Pi 3.141592653589793

using namespace std;
typedef pair< long double, long double> pdd;

pdd _minus(pdd a, pdd b){
  return pdd(a.ff - b.ff, a.ss - b.ss);
}

long double cross(pdd a, pdd b){
  return a.ff*b.ss - a.ss*b.ff;
}

long double length(pdd a, pdd b){
  pdd aux = _minus(a, b);
  return (aux.ff*aux.ff + aux.ss*aux.ss);
}

long double area(pdd a, pdd b, pdd c){
  long double ar = 0.0;
  ar = cross(_minus(b, a), _minus(c, a));
  if(ar < 0.00001)  ar = -ar;
  return  ar/2.0;
}

int main(){
  ios_base::sync_with_stdio(0);
  pdd a, b, c;
  long double r, ar;
  while(cin >> a.ff){
    cin >> a.ss >> b.ff >> b.ss >> c.ff >> c.ss;
    ar = area(a, b, c);
    r = (length(a, b)*length(a, c)*length(b, c));
    r /= (16*ar*ar);
    r = 2.0*sqrt(r);
    cout << fixed << setprecision(2) <<  r*Pi << "\n";
  }


  return 0;
}
