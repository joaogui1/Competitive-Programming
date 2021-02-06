#include <bits/stdc++.h>

using namespace std;

int a[300300];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, k, i = 0, j = 0, sum = 0, ans = 0, x, y;
  cin >> n >> k;
  for(int i = 0; i < n; ++i)  cin >> a[i];
  while(i < n){
    while(j < n){
      if(a[j++] == 0) sum += 1;
      if(sum > k) break;
      if(ans < j - i)
        ans = j - i, y = j, x = i;
    }
    if(j == n)  break;
    while(sum > k){
      if(a[i] == 0) sum -= 1;
      ++i;
    }
  }

  cout << ans << "\n";
  // cout << x << " " << y << "\n";
  for(int i = x; i < y; ++i) a[i] = 1;
  for(int i = 0; i < n; ++i)  cout << a[i] << " \n"[i + 1 == n];


  return 0;
}
