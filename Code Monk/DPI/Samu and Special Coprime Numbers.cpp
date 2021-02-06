#include<bits/stdc++.h>
#define gcd __gcd

using namespace std;
typedef long long int ll;

ll dp[32][256][1600];
int digits[32];

ll solve(int pos, int sum, int sqsum, bool check){
  if(pos == -1) return (gcd(sum, sqsum) == 1);
  if(!check && dp[pos][sum][sqsum]!= -1) return dp[pos][sum][sqsum];

  ll ans = 0;
  int last;
  if(check) last = digits[pos];
  else  last = 9;

  for(int i = 0; i <= last; ++i)
    ans += solve(pos - 1, sum + i, sqsum + i*i, check && i == last);

  if(!check)
    dp[pos][sum][sqsum] = ans;

  return ans;
}

ll solve(ll n){
  if(n == 0)  return 0;

  int len = 0;
  for(; n; n /= 10)
    digits[len++] = n % 10;


  ll ans = solve(len - 1, 0, 0, 1);
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t;
  ll l,r;
	memset(dp, -1, sizeof dp);

  cin >> t;
  while(t--){
    cin >> l >> r;
    cout << solve(r) - solve(l-1) << "\n";
  }

  return 0;
}
