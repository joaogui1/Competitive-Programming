#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main(){
  ios_base::sync_with_stdio(0);
  long double d, h, v, e, pi = 3.1415926535;
  cin >> d >> h >> v >> e;
  e *= (pi*(d/2)*(d/2));
  h *= (pi*(d/2)*(d/2));
  if(e > v + 0.0000001) cout << "NO\n";
  else{
    v -= e;
    cout << "YES\n";
    cout << h/v << "\n";
  }



  return 0;
}
