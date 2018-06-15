#include <bits/stdc++.h>
#define ff first
#define ss second
#define pi 3.1415926535

using namespace std;
typedef complex <double> c;
typedef pair <string, double> psi;

vector <psi> com;

int main(){
  ios_base::sync_with_stdio(0);
  psi aux;
  int n, t;
  complex <double> pos, ang;
  cin >> t;
  while(t--){
    cin >> n;
    com.clear();
    for(int i = 0; i < n; ++i){
      cin >> aux.ff >> aux.ss;
      com.push_back(aux);
    }
    ang = c(1, 0);
    pos = c(0, 0);

    for(int i = 0; i < n; ++i){
      if(com[i].ff == "fd")
        pos += (com[i].ss*ang);

      else if(com[i].ff == "bk")
        pos -= (com[i].ss*ang);

      else if(com[i].ff == "rt")
        ang *= c(cos(-pi*com[i].ss/180.0), sin(-pi*com[i].ss/180.0));
      else
        ang *= c(cos(pi*com[i].ss/180.0), sin(pi*com[i].ss/180.0));
      //cout << pos << " " << ang << "\n";
    }
    cout << fixed << setprecision(0) << (abs(pos)) << "\n";

  }


  return 0;
}
