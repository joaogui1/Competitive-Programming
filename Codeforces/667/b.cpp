#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

ll le[100010], x = 0;

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i)  cin >> le[i];
  sort(le, le + n);
  for(int i = 0; i < n - 1; ++i) x += le[i];
  x = le[n - 1] - x;
  ++x;
  cout << x << "\n";

  return 0;
}
