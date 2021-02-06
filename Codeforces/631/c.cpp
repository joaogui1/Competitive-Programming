#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int a[1 << 19], b[1 << 19], op[1 << 19], r[1 << 19];

int main(){
  ios_base::sync_with_stdio(0);
  int n, m, opp, rr, aux = 0, bl, br;
  cin >> n >> m;
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  for(int i = 0; i < m; ++i, ++aux){
    cin >> opp >> rr;
    for(; aux > 0 && rr > r[aux - 1]; --aux);
    op[aux] = opp, r[aux] = rr;
  }
  bl = 0, br = r[0], r[aux++] = 0;

  for(int i = 0; i < br; ++i)
    b[i] = a[i];
  sort(b, b + br);

  for(int i = 1; i < aux; ++i)
    for(int j = r[i - 1]; j > r[i]; --j)
      a[j - 1] = (op[i - 1] == 1) ? b[--br] : b[bl++];


  for(int i = 0; i < n; ++i)
    cout << a[i] << " \n"[i == n - 1];


  return 0;
}
