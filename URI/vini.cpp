#include <bits/stdc++.h>
#define INF (1LL << 58)

using namespace std;
typedef long long int ll;

ll cnt[64][1024][1024], dp[1024][1024], p[4][64][1024], a[4][1024];
int n, sz[2], p0, p1;

void initialize(){
  memset(a, 0, sizeof a);
  memset(dp, -1, sizeof dp);
  memset(cnt, 0, sizeof cnt);
}

long long int f(int p1, int p2){
    if(a[0][p1] != a[1][p2])  return INF;
    if(dp[p1][p2] != -1) return dp[p1][p2];
    dp[p1][p2] = INF;
    for(int i = 1; i <= n; ++i){
        if(p[0][i][p1] == -1 || p[1][i][p2] == -1){
            return dp[p1][p2] = 1;
        }

        else{
            int px = p[0][i][p1];
            int py = p[1][i][p2];
            dp[p1][p2] = min(dp[p1][p2], f(px, py) + 1);
        }
    }
    return dp[p1][p2];
}

int main(){
  ios_base::sync_with_stdio(0);

  while(cin >> n >> sz[0] >> sz[1]){
    initialize();
    for(int i = 0; i < 2; ++i)
      for(int j = 0; j < sz[i]; ++j)  cin >> a[i][j];
    a[0][ sz[0] ] = 90;
    a[1][ sz[1] ] = 90;
    for(int i = 0; i < 2; ++i){
      for(int j = 1; j <= n; ++j){
        int prev = -1;
        for(int k = 0; k <= sz[i]; ++k){
          p[i][j][k] = prev;
          if(a[i][k] == j)  prev = k;
        }
      }
    }

    f(sz[0], sz[1]);
    cout << dp[sz[0]][sz[1]] << " " << cnt[n][sz[0]][sz[1]] << "\n";
  }

  return 0;
}
