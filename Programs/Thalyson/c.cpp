#include <bits/stdc++.h>

using namespace std;

deque <int> a;
int freq[5010], sum[5010];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, test, ans = 0;
  ifstream fin ("input.txt");
  ofstream fout ("output.txt");
  cin >> n;
  a.assign(n, 0);
  for(int i = 0; i < n; ++i)  cin >> a[i];
  for(int i = 0; i < n; ++i)  ++freq[a[i]];
  for(int i = 1; i < 5001; ++i){
    test = 0;
    if(freq[i] != 0){
      for(int j = 2*i + 1; j < 5001; ++j) test += freq[j];
      if(test >= freq[i]){
        ans += freq[i];
        freq[i] = 0;
      }
      else{
        ans += test;
        for(int j = 2*i + 1; j < 5001; ++j) freq[j] = 0;
      }
    }
  }

  cout << ans << "\n";
  return 0;
}
