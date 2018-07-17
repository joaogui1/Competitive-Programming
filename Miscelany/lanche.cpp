#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 260
#define INF 999999999
using namespace std;
int dist[MAXN][MAXN], n, m, maxdist[MAXN];
void fw(){
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
int main(){
    int a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dist[i][j] = INF;
    for(int i = 1; i <= n; ++i)
        dist[i][i] = 0;
    for(int i = 1; i <= m; ++i){
        scanf("%d %d %d", &a, &b, &c);
        if(dist[a][b] > c)
            dist[a][b] = dist[b][a] = c;
    }
    fw();
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if(dist[i][j] > maxdist[i])
                maxdist[i] = dist[i][j];
        }
    }
    sort(maxdist + 1, maxdist + n + 1);
    printf("%d\n", maxdist[1]);
    return 0;
}
