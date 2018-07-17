#include "aliens.h"
#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

long long take_photos(int n, int m, int k, std::vector<int> r, std::vector<int> c) {
    int x, y;
    pll points[100100];
    ll dp[1010][1010],  cost[1010];
    for(int i = 0; i < n; ++i)	points[i + 1].ff = r[i], points[i + 1].ss = c[i];
    for(int i = 1; i <= n; ++i){
    	x = min(x, min(r[i - 1], c[i - 1]));
	    y = max(y, max(r[i - 1], c[i - 1]));
	    cost[i] = y - x;
	    cost[i] *= cost[i];
            dp[i][1] = cost[i];
    }
    for(int i = 1; i <= n; ++i)	cout << cost[i] << " \n"[i == n];
    for(int i = 1; i <= n; ++i)
	    for(int j = 2; j <= k; ++j){
	      dp[i][j] = m*m;
	      for(int l = 1; l <= i; ++l)
	        dp[i][j] = min(dp[i][j], dp[l][j - 1] + cost[i] - cost[l]);
	      //cout << dp[i][j] << " \n"[j == k];
	    }
  return dp[n][k];
  
}
