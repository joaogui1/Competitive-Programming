#include <bits/stdc++.h>

using namespace std;

int freq[5010], ans[5010], a[5010];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, idx;
  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];

  for(int i = 1; i <= n; ++i){
    memset(freq, 0, sizeof freq);
    //freq[a[i]] = 1;
    idx = a[i];
    for(int j = i; j <= n; ++j){
      ++freq[a[j]];
      if(freq[a[j]] > freq[idx] || (freq[a[j]] == freq[idx] && a[j] < idx))  idx = a[j];
      ++ans[idx];
    }
  }
  for(int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];


  return 0;
}
