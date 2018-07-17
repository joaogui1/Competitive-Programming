#include <bits/stdc++.h>

using namespace std;

int n, x[200100], ans[200100];

bool test(){
  for(int i = 1; i <= n; ++i)
    if(ans[i] > x[i]) return 1;
    else if(ans[i] < x[i])  return 0;
  return 0;
}

void f(int pos){
  if(pos == n + 1){
    if(test())  for(int i = 1; i <= n; ++i) ans[i] = x[i];
    return;
  }
  int mn = min(x[pos], min(x[2*pos], x[2*pos + 1]));
  if(mn == x[pos])  f(pos + 1);
  else if(mn == x[2*pos]){
    swap(x[pos], x[2*pos]), f(pos + 1);
    swap(x[pos], x[2*pos]);
  }
  else{
      swap(x[pos], x[2*pos + 1]), f(pos + 1);
      swap(x[2*pos], x[2*pos + 1]), f(pos + 1);
      swap(x[2*pos], x[2*pos + 1]), swap(x[pos], x[2*pos + 1]);
  }

}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> n;
  for(int i = 1; i <= n; ++i) ans[i] = n;
  for(int i = 1; i <= n; ++i)  cin >> x[i];
  for(int i = 1; i <= n + 1; ++i) x[i + n] = n + 1;
  for(int i = 1; i <= n; ++i) ans[i] = n + 1;
  f(1);
  for(int j = 1; j <= n; ++j) cout << ans[j] << " \n"[j == n];

  return 0;
}
