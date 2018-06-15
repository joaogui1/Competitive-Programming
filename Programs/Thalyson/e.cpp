#include <bits/stdc++.h>

using namespace std;

int a[32];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, c = 0, bi = 0, ba = 0;
  cin >> n;
  for(int i = 0; i < n; ++i)  cin >> a[i];
  for(int i = 0; i < n; i += 3)  c += a[i];
  for(int i = 1; i < n; i += 3) bi += a[i];
  for(int i = 2; i < n; i += 3) ba += a[i];
  if(c < bi)  cout << ((bi > ba)?("biceps\n"):("back\n"));
  else
    cout << ((c > ba)?("chest\n"):("back\n"));

  return 0;
}
