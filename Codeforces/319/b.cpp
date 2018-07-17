#include <bits/stdc++.h>

using namespace std;

int v[100100], pos[100100], ki[4][100100];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m = 0, aux = 0, ans = 0, m2, x;
  cin >> n;

  for(int i = 0; i < n; ++i)
    cin >> v[i];


  for(int i = 0; i < n; ++i){
    pos[i] = i + 1;
    if(i + 1 < n && v[i] > v[i + 1]) ki[0][m++] = i;
  }

  while(m > 0){
    m2 = 0;
    for(int i = m - 1; i >= 0; --i){
      x = ki[aux][i]; //kills
      pos[x] = pos[pos[x]];
      if(pos[x] < n && v[x] > v[pos[x]]) ki[aux^1][m2++] = x; //see if he will kill again
    }
    aux ^= 1;
    m = m2;
    reverse(ki[aux], ki[aux] + m);
    ++ans;
  }

  cout << ans << "\n";
  return 0;
}
