#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 110
int mark[MAXN][MAXN], G[MAXN][MAXN], dx[3] = {-1, 0, 1}, dy[3] = {-1, 0, 1};
void marcar(int x, int y){
    mark[x][y] = 1;
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; j++)
            if(G[x+dx[j]][y+dy[i]] && !mark[x+dx[j]][y+dy[i]])   marcar(x+dx[j], y+dy[i]);
    return;
}

int main(){
    int n, m, ans;
    char aux;
    while(1){
        ans = 0;
        scanf("%d", &m);
        if(m == 0)  break;
        memset(mark, 0, sizeof(mark));
        memset(G, 0, sizeof(G));
        scanf("%d", &n);
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j){
                scanf(" %c", &aux);
                if (aux == '@') G[j][i] = 1;
            }
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
                if(G[j][i] && !mark[j][i]){
                    marcar(j, i);
                    ++ans;
                }
        printf("%d\n", ans);
    }

    return 0;
}
