#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <int, int> pii;

int freq[1 << 20];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans = 0, a;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a;
    if(freq[a]) --freq[a];
    else  ++ans;
    ++freq[a - 1];
  }
  cout << ans << "\n";
  return 0;
}
