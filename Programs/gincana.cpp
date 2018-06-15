#include<cstdio>
#include<cstdlib>
bool amizades[1010][1010], mark[1010];
void dfs(int v, int n){
    mark[v] = 1;
    for(int i = 0; i <= n; ++i )
        if(!mark[i] && amizades[v][i])
            dfs(i, n);
    return;
}
int main(){
    int n, m, a, b, ans = 0;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &a, &b);
        amizades[a][b] = amizades[b][a] = 1;
    }
    for(int i = 1; i <= n; ++i){
        if(!mark[i]){
            dfs(i, n);
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}
