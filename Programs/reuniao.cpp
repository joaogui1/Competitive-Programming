#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 110
#define INF 1000100
using namespace std;
int dist[MAXN][MAXN], n, m, maxdist[MAXN];
void fw(){
    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
int main(){
    int a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = INF;
    for(int i = 0; i < m; ++i){
        scanf("%d %d %d", &a, &b, &c);
        if(dist[a][b] > c)
            dist[a][b] = dist[b][a] = c;
    }
    fw();
    for (int i = 1; i < n; ++i){
        for (int j = 1; j < n; ++j){
            if(dist[i][j] > maxdist[i])
                maxdist[i] = dist[i][j];
        }
    }
    sort(maxdist, maxdist + n);
    printf("%d\n", maxdist[0]);
    return 0;
}
