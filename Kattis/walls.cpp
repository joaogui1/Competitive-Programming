#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <double, double> pdd;

pdd doors[8];
vector <pdd> v;
long long int s[8];

double dist(pdd a, pdd b){
  return (a.ff - b.ff)*(a.ff - b.ff) + (a.ss - b.ss)*(a.ss - b.ss);
}

int main(){
  ios_base::sync_with_stdio(0);
  ll aux;
  pdd aup;
  bool vdc;
  double l, w, n, r;
  cin >> l >> w >> n >> r;
  doors[1] = pii(l/2, 0);
  doors[2] = pii(0, w/2);
  doors[0] = pii(-l/2, 0);
  doors[3] = pii(0, -w/2);
  for(int i = 0; i < n; ++i){
    cin >> aup.ff >> aup.ss;
    v.push_back(aup);
  }

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < 4; ++j)
      if(dist(v[i], doors[j]) <= r*r) s[j] |= (1LL << i);
  for(int i = 0; i < 4 && vdc; ++i)
    if(s[i] == 0){
      vdc = 1;
      cout << "impossible\n";
    }
  aux = (s[0] & s[1]) & (s[2] & s[3]);

  for(int i = 0; i < n && vdc; ++i)
    if(aux & (1LL << i)){
      vdc = 1;
      cout << "1\n";
    }
  aux = s[0] & s[1] & s[2];
  




  return 0;
}
