#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

map <ll, int> freq;
ll pre[100100], v[100100], f = -1;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i)  cin >> v[i], pre[i] = pre[i - 1] + v[i];
  for(int i = 1; i <= n; ++i){
    if(freq.count(pre[i]) == 0) freq[pre[i]] = 0;
    if(++freq[pre[i]] > f)  f = freq[pre[i]];
  }
  cout << n - f << "\n";
  return 0;
}
