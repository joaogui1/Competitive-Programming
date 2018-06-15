#include <bits/stdc++.h>
#define MOD 1000000007LL

using namespace std;
typedef long long int ll;

int n, k, sizes[1024];
ll dp[1024];
vector <int> brushes;

ll f(int pos){
  if(pos == n || pos == n + 1)  return 1LL;
  //if(pos > n)   return 0LL;
  if(dp[pos] != -1)  return dp[pos];
  dp[pos] = 0;
  for(int const & b : brushes){
    if(pos + b < n + 2) dp[pos] += f(pos + b + 1);
    if(dp[pos] > MOD) dp[pos] %= MOD;
  }
  return dp[pos];
}

int main(){
  ios_base::sync_with_stdio(0);
  int aux;
  cin >> n >> k;
  for(int i = 0; i < n; ++i)  dp[i] = -1;
  while(k--){
    cin >> aux;
    brushes.push_back(aux);
  }

  sizes[0] = 1;
  for(int i = 0; i < n + 1; ++i)
    for(int j = 0; j < brushes.size(); ++j)
      if(i >= brushes[j]) sizes[i] |= sizes[i - brushes[j]];

  brushes.clear();
  for(int i = 0; i < n + 1; ++i) if(sizes[i])  brushes.push_back(i);

  cout << f(0) << "\n";

  //for(int i = 0; i <= n; ++i)  cout << f(i) << endl;

  return 0;
}
