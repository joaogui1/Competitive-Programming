#include <bits/stdc++.h>

using namespace std;

int ans, arr[1 << 20];

void initialize(){
  ans = 0;
  memset(arr, 0, sizeof arr);
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, a, b;
  cin >> t;
  while(t--){
    cin >> n;
    initialize();

    while(n--){
      cin >> a >> b;
      ++arr[a];
      if(arr[b] == 0) ++ans;
      else  --arr[b];
    }
    cout << ans << "\n";
  }


  return 0;
}
