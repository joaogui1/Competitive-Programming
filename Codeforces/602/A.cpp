#include <bits/stdc++.h>

using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  long long int comp, n, m, bx, by, x = 0, y = 0, aux, ex;

  cin >> n >> bx;
  ex = 1;
  for(int i = 0; i < n - 1; ++i)  ex*=bx;
  for(int i = 0; i < n; ++i, ex/=bx){
    cin >> aux;
    x += ex*aux;
  }
  cin >> m >> by;
  ex = 1;
  for(int i = 0; i < m - 1; ++i)  ex*=by;
  for(int i = 0; i < m; ++i, ex/=by){
    cin >> aux;
    y += ex*aux;
  }

  if(x > y) cout << ">\n";

  else if(x < y)  cout << "<\n";

  else  cout << "=\n";


  return 0;
}
