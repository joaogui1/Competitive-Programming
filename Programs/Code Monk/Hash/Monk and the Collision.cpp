#include <bits/stdc++.h>

using namespace std;

int arr[16], ans;

void initialize(){
  ans = 0;
  memset(arr, 0, sizeof arr);
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, x;
  cin >> t;
  while(t--){
    cin >> n;
    initialize();
    while(n--){
      cin >> x;
      if(arr[x%10] > 0) ++ans;
      ++arr[x%10];
    }
    cout << ans << "\n";
  }



  return 0;
}
