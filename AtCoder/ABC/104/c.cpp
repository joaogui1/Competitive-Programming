#include <bits/stdc++.h>

using namespace std;
int p[110], c[110], n;
int dp[11][1101];

int f(int pos, int prob){
    if(pos > n) return 0;
    if(prob == 0)   return 0;
    if(dp[pos][prob] != -1) return dp[pos][prob];

    for(int i = 0; i <= p[pos] && i <= prob; ++i)
        dp[pos][prob] = max(dp[pos][prob], f(pos + 1, prob - i) + 100*pos*i + (i == p[pos])*c[pos]);
    return dp[pos][prob];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int g, ans = 0, sum = 0;
    cin >> n >> g;
    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; ++i)  cin >> p[i] >> c[i], sum += p[i];
    for(int i = 1; i <= sum; ++i)   f(1, i);
    for(int i = 1; i <= sum; ++i){
        for(int j = 1; j <= n; ++j)
            if(dp[j][i] >= g){
                cout << i << "\n";
                return 0;
            }
    }

    return 0;
}