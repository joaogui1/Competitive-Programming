#include <bits/stdc++.h>
#define oo (1LL << 50)

using namespace std;
typedef long long int ll;

int c[128];
ll dp[128][128][128], cost[128][128], idx[128][128], m1[128][128], m2[128][128];

int main(){
  cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m, k;
  cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= k; ++j){
			m1[i][j] = INF; m2[i][j] = INF; idx[i][j] = -1;
			for(int a = 0; a <= m; a++)
			{
				dp[i][j][a] = INF;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> cost[i][j];
		}
	}
	if(c[1] == 0)
	{
		for(int i = 1; i <= m; i++)
		{
			dp[1][1][i] = cost[1][i];
			if(dp[1][1][i] <= m1[1][1])
			{
				if(dp[1][1][i] == m1[1][1])
				{
					idx[1][1] = -2;
				}
				else
				{
					idx[1][1] = i;
				}
				m2[1][1] = m1[1][1];
				m1[1][1] = dp[1][1][i];
			}
			else if(dp[1][1][i] <= m2[1][1])
			{
				m2[1][1] = dp[1][1][i];
			}
		}
	}
	else
	{
		dp[1][1][c[1]] = 0;
		m1[1][1] = 0; idx[1][1] = c[1];
	}
	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(c[i] == 0)
			{
				for(int a = 1; a <= m; a++)
				{
					dp[i][j][a] = min(dp[i][j][a], dp[i-1][j][a] + cost[i][a]);
					ll tmp = INF;
					if(a == idx[i-1][j-1])
					{
						tmp = m2[i-1][j-1];
					}
					else
					{
						tmp = m1[i-1][j-1];
					}
				    dp[i][j][a] = min(dp[i][j][a], tmp + cost[i][a]);
				}
			}
			else
			{
				dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i-1][j][c[i]]);
				for(int b = 1; b <= m; b++)
				{
					if(b != c[i]) dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i-1][j-1][b]);
				}
				//cout << i << ' ' << j << ' ' << c[i] << ' ' << dp[i][j][c[i]] << '\n';
			}
			for(int a = 1; a <= m; a++)
			{
				if(dp[i][j][a] <= m1[i][j])
				{
					if(dp[i][j][a] == m1[i][j])
					{
						idx[i][j] = -2;
					}
					else
					{
						idx[i][j] = a;
					}
					m2[i][j] = m1[i][j];
					m1[i][j] = dp[i][j][a];
				}
				else if(dp[i][j][a] <= m2[i][j])
				{
					m2[i][j] = dp[i][j][a];
				}
			}
		}
	}
	ll ans = INF;
	for(int i = 1; i <= m; i++)
	{
		ans = min(ans, dp[n][k][i]);
	}
	if(ans >= INF) ans = -1;
	cout << ans;
}
