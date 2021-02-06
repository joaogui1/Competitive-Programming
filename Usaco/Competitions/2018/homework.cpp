#include <bits/stdc++.h>

using namespace std;

int v[100100] = {0}, mini[100100] = {0}, ans[100100];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ifstream cin ("homework.in");
  ofstream cout ("homework.out");
  int n, id = 0;
  int big = 0, test;
  cin >> n;
  for(int i = 1; i <= n; ++i)  cin >> v[i];
  mini[n] = v[n];
  for(int i = n - 1; i > 0; --i) mini[i] = min(mini[i + 1], v[i]);
  for(int i = n; i > 0; --i)  v[i] += v[i + 1]; // suffix
  for(int i = 1; i < n - 1; ++i){
    test = v[i + 1] - mini[i + 1];
    test /= (n - i - 1);
    if(test > big){
      id = 0;
      big = test;
      ans[id] = i;
    }
    else if(test == big)  ans[++id] = i;
  }
  for(int i = 0; i <= id; ++i) cout << ans[i] << "\n";


  return 0;
}
