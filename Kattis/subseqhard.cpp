#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll v[1 << 20];
map <ll, int> freq;

int main(){
  ios_base::sync_with_stdio(0);
  int t, n;
  ll ans;
  cin >> t;
  while(t--){
    cin >> n;
    ans = 0;
    freq.clear();
    freq[0] = 1;
    for(int i = 0; i < n; ++i)  cin >> v[i];
    for(int i = 1; i < n; ++i)  v[i] += v[i - 1];
    for(int i = 0; i < n; ++i){
      if(freq.count(v[i]) == 0) freq[v[i]] = 0;
      ++freq[v[i]];
      if(freq.count(v[i] - 47) == 0)  freq[v[i] - 47] = 0;
      ans += freq[v[i] - 47];
    }

    cout << ans << "\n";
  }



  return 0;
}
