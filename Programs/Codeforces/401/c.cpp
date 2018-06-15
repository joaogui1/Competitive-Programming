#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, aux = -1;
  cin >> n >> m;
  if(m < n - 1 || 2*n + 2 < m)
    cout << -1;
  else
    while(m + n > 0){
      if((m > n && aux < 2) || aux == 0){
        --m;
        if(aux == -1) ++aux;
        ++aux;
        cout << 1;
      }
      else{
        --n;
        aux = 0;
        cout << 0;
      }
    }
  cout << "\n";
  return 0;
}
