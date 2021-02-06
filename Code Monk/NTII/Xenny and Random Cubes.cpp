#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

string s;
int die[16][36];
long long int ans, add;
vector <int> order, k_ones;

int ones(int x){
  int ret = 0;
  for(; x > 0; x -= x&-x, ++ret);
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, k;
  char aux;
  cin >> n >> k;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < 6; ++j){
      cin >> aux;
      ++die[i][aux - 'a'];
    }
  cin >> s;
  //k = s.size();

  for(int i = 0; i < (1 << n); ++i) if(ones(i) == k)  k_ones.push_back(i);

  ans = 0;
  for(int const & mask : k_ones){
    order.clear();
    for(int i = 0; i < n; ++i)
      if(mask & (1 << i)) order.push_back(i);

    while(1){
      add = 1LL;
      for(int i = 0; i < k; ++i)
        add *= die[order[i]][s[i] - 'a'];
      ans += add;
      //if(add != 0)  cout << add << endl;
      if(ans >= MOD)  ans %= MOD;
      if(!next_permutation(order.begin(), order.end())) break;
    }

  }
  cout << ans << "\n";

  return 0;
}
