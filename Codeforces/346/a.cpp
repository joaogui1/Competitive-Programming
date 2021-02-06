#include <bits/stdc++.h>

using namespace std;

int a[128];
string out[2] = {"Bob", "Alice"};

int gcd(int a, int b){
  if(a%b == 0)  return b;
  return gcd(b, a%b);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans;
  cin >> n;
  for(int i = 0; i < n; ++i)  cin >> a[i];
  sort(a, a + n);
  ans = a[0];
  for(int i = 1; i < n; ++i)  ans = gcd(ans, a[i]);
  cout << out[(a[n - 1]/ans - n)%2] << "\n";

  return 0;
}
