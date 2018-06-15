#include<cstdio>
#include <queue>
#include<cstdlib>
#include <utility>
#include<algorithm>
#define MAXN 110
using namespace std;
queue <pair <int, int> > q;
int G[MAXN][MAXN], tamanho[MAXN], n, m;
int monta_navio(int y, int x, int nav){
    int ret = 1;
    pair <int, int> davez;
    davez.first = y;davez.second = x;
    q.push(davez);
    while(!q.empty()){
        davez = q.front();q.pop();
        G[davez.first][davez.second] = nav;
        printf("estou na casa %d %d pertencente ao navio %d\n", davez.first, davez.second, G[davez.first][davez.second]);
        if(davez.first + 1 <= n && G[davez.first + 1][davez.second] == 1){
            ++ret;
            q.push(make_pair(davez.first + 1, davez.second));
            printf("%d\n", G[davez.first + 1][davez.second] == 1);
            getchar();
        }
        if(davez.first - 1 > 0 && G[davez.first - 1][davez.second] == 1){
            ++ret;
            q.push(make_pair(davez.first - 1, davez.second));
            getchar();
        }
        if(davez.second + 1 <= m && G[davez.first][davez.second + 1] == 1){
            ++ret;
            q.push(make_pair(davez.first, davez.second+1));
            getchar();
        }
        if(davez.second - 1 > 0 && G[davez.first][davez.second - 1] == 1){
            ++ret;
            q.push(make_pair(davez.first, davez.second-1));
            getchar();
        }
    }
    return ret;
}
int main(){
    int jog, auxX, auxY, ans = 0, cont = 0, nav = 2;
    char aux;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            scanf(" %c", &aux);
            if(aux == '#')  G[i][j] = 1;
        }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(G[i][j] == 1){
                tamanho[nav] = monta_navio(i, j, nav);
                nav++;
            }
    scanf("%d", &jog);
    for(int i = 1; i <= jog; ++i){
        scanf("%d %d", &auxY, &auxX);
        if(G[auxY][auxX])
            if (--tamanho[G[auxY][auxX]] == 0)
                ++ans;
    }

    for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j)
                printf("%d ", G[i][j]);
            printf("\n");
            }
    printf("%d\n", ans);


    return 0;
}

