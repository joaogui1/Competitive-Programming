#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

long long int a[200000];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  long long int n, k, sq;
  cin >> n >> k;
  for(int i = 1; i <= n; ++i)  cin >> a[i];
  for(sq = n; sq*(sq + 1)/2 >= k; --sq);
  sq = sq*(sq + 1)/2;
  cout << a[k - sq] << "\n";

  return 0;
}
