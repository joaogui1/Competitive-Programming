#include <cstring>
#include <iostream>

//using namespace std;
typedef long long int ll;

int sta, end, n;
ll dp[2010][2010];
static ll MOD = 1000000007;


ll f(int i, int k){
  if(k < 0) return 0;
  if(i == n - 1)  return k == 0;

  ll ks = i > sta;
  ll ke = i > end;

  ll &ret = dp[i][k];
  if(ret != -1) return ret;
  ret = 0;

  if(i == sta || i == end){
    ret += f(i + 1, k);
    ret += f(i + 1, k - 1)*k;
  }
  else{
    ret += f(i + 1, k + 1);
    ret += f(i + 1, k - 1)*k*(k - 1 + ks + ke);
  }

  return (ret %= MOD);
}

int main(){
  std::cin.tie(0);
  memset(dp, -1, sizeof dp);
  std::ios_base::sync_with_stdio(0);
  std::cin >> n >> sta >> end;
  --sta, --end;
  std::cout << f(0, 0) << "\n";

  return 0;
}
