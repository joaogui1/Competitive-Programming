#include <cstring>
#include <iostream>

//using namespace std;
typedef long long int ll;

std::string s;
int sta, end, n;
ll dp[2010][2010];
static ll MOD = 1000000007;


ll f(int i, int k){
  int ks = i > sta;
  int ke = i > end;
  if(k < 0) return 0;

  if(i == n - 1){
    if(i == end)  return k == 0;
    else  if(i == sta)  return (k == 0 && s[i] != 'R') ;
    else return (k == 0 &&  s[i] != 'R');
  }
  ll &ret = dp[i][k];
  if(ret != -1) return ret;
  ret = 0;
  if(i != sta && i != end){
    ret += s[i] != 'L' ? f(i + 1, k + 1) : 0; //new component
    ret += s[i] != 'L' ? f(i + 1, k)*(k + ks) : 0; //connect to a component by the left
    ret += s[i] != 'R' ? f(i + 1, k)*(k + ke) : 0; //connect to a component by the right
    ret += s[i] != 'R' ? f(i + 1, k - 1)*k*(ks + ke + (k - 1)) : 0; //connects to components
  }
  else if(i == sta){
    ret += s[i] != 'L'?f(i + 1, k):0;
    ret += s[i] != 'R'?f(i + 1, k - 1)*k:0;
  }
  else{
    ret += f(i + 1, k);
    ret += f(i + 1, k - 1)*k;
  }
  return (ret %= MOD);
}

int main(){
  std::cin.tie(0);
  memset(dp, -1, sizeof dp);
  std::ios_base::sync_with_stdio(0);
  std::cin >> s >> sta >> end;
  --sta, --end;
  n = s.size();
  std::cout << f(0, 0) << "\n";

  return 0;
}
