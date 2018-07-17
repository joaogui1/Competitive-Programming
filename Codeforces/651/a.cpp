#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main(){
  ios_base::sync_with_stdio(0);
  int a, b, ans = 0;
  cin >> a >> b;
  if(a < 2 && b < 2)  cout << 0 << "\n";
  else{
    for(;a > 0 && b > 0; a -= 2, b -= 2){
      ++ans;
      if(a < b) a += 3;
      else  b += 3;
    }
    cout << ans << "\n";
  }

  return 0;
}
