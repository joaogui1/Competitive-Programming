//casos 21-25
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

set <int> st;
set <pii> e;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  srand(time(0));
  int n, m, k, u, v, w;
  n = 10000, m = 100000, k = 1000;
  cout << n << " " << m << " " << k << "\n";
  for(int i = 1; i <= 1000; ++i)
    cout << i << " \n"[i == 1000];
  for(int i = 0; i < n; ++i){
    while(1){
      v = rand() % n;
      if(i != v && e.count(pii(i, v)) == 0)  break;
    }
    e.insert(pii(i, v)), e.insert(pii(v, i));
    w = (rand() % 1000) + 1;
    cout << i << " " << v << " "<< w << "\n";
  }
  for(int i = n; i < m; ++i){
    while(1){
      u = rand() % n;
      v = rand() % n;
      if(u != v && e.count(pii(i, v)) == 0 )  break;
    }
    e.insert(pii(u, v)), e.insert(pii(v, u));
    w = (rand() % 1000) + 1;
    cout << u << " " << v << " "<< w << "\n";
  }

  return 0;
}
