#include <cstdio>
#include <cstdlib>
struct cipo{
    int x;
    int y;
    int viz[1010]; //posicao zero guarda o numero de vizinhos
};
cipo g[1010];
int mark[1010];
int dist (int i, int j) {return ((g[i].x-g[j].x)*(g[i].x-g[j].x) + (g[i].y-g[j].y)*(g[i].y-g[j].y));}
void dfs(int v, int n){
    mark[v] = 1;
    for(int i = 1; i <= g[v].viz[0]; ++i)
        if(!mark[g[v].viz[i]])
            dfs(g[v].viz[i], n);
    return;
}
int main(){
    int n, d, x, y, ans = 1;
    scanf("%d%d", &n, &d);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d", &g[i].x , &g[i].y);
        for(int j = 1; j < i; ++j){
            if(dist(i, j) <= d*d){
                g[i].viz[++g[i].viz[0]] = j;
                g[j].viz[++g[j].viz[0]] = i;
            }
        }
    }
    dfs(1, n);
    for(int i = 1; i <= n; ++i)
        if(!mark[i]){
            ans = 0;
        }
    if(ans)    printf("S\n");
    else printf("N\n");
    return 0;
}
