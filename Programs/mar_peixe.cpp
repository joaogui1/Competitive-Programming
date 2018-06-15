#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>
#define MAXN 110
using namespace std;
int G[MAXN][MAXN], mark[MAXN][MAXN];
int main(){
    int n, xi, xf, yi, yf, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d %d %d %d", &xi, &xf, &yi, &yf);
        for(int j = xi; j < xf; ++j)
            for(int k = yi; k < yf; ++k)
                G[j][k] = 1;
    }
    for(int j = 1; j <= MAXN; ++j)
            for(int k = 1; k <= MAXN; ++k)
                if(G[j][k]) ++ans;
    printf("%d\n", ans);

    return 0;
}

