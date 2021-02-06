#include <bits/stdc++.h>

using namespace std;

int v[128], u[128];

void inv(int l, int r){
  for(int i = l; i < r; i += 2)
    swap(v[i], v[i + 1]);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, pos;
  cin >> n;
  for(int i = 0; i < n; ++i)  cin >> v[i], u[i] = v[i];
  sort(u, u + n);
  for(int i = 0; i < n; ++i){
    for(int j = i; j < n; ++j)
      if(u[i] == v[j]){
        pos = j;
        break;
      }
    while(pos != i){
      cout << pos << " " << pos + 1 << "\n";
      swap(v[pos], v[pos - 1]);
      --pos;
    }
  }

  return 0;
}
