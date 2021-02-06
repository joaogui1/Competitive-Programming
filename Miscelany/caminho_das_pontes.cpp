#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 1010
#define INF 999999999

using namespace std;
int G[MAXN][MAXN], dist[MAXN], mark[MAXN], n, m;
void djikstra(int v){
    for(int i = 0; i <= n; ++i) dist[i] = G[v][i];
    dist[v] = 1;
    mark[v] = 1;

    while (true){
        int davez = -1;
        int min_dist = INF;

        for(int i = 0; i <= n; ++i){
            if(!mark[i] && dist[i] < min_dist){
                davez = i;
                min_dist = dist[i];
            }
        }
        if(davez == -1) break;
        mark[davez] = 1;
        for(int i = 0;i <= n;i++)
            dist[i] = min(dist[i], dist[davez] + G[davez][i]);

    }

}
int main(){
    int a, b, c;
    scanf("%d %d", &n, &m);
    n += 1;
    for(int i = 0;i <= n;i++)
        for(int j = 0;j <= n;j++)
            G[i][j] = INF;
    for(int i = 1; i <= m; ++i){
        scanf("%d %d %d", &a, &b, &c);
        G[a][b] = c; G[b][a] = c;
    }
    djikstra(0);
    printf("%d\n", dist[n]);
    return 0;
}

