#include<cstdio>
#include <queue>
#include<cstdlib>
#include <utility>
#include<algorithm>
#define MAXN 110
using namespace std;
pair <int, int> pos[MAXN];
queue <pair <int, int> > q;
int n, m, G[MAXN][MAXN], mark[MAXN][MAXN];
bool died(int auxY, int auxX){
    pair <int, int> davez;
    q.push(make_pair(auxY, auxX));
    while(!q.empty()){
        davez = q.front();q.pop();
        mark[davez.first][davez.second] = 1;
        if(G[davez.first+1][davez.second] == 1)    return 0;
        if(G[davez.first-1][davez.second] == 1)    return 0;
        if(G[davez.first][davez.second+1] == 1)    return 0;
        if(G[davez.first][davez.second-1] == 1)    return 0;
        if(G[davez.first+1][davez.second] == 0 && G[davez.first-1][davez.second] == 0 && G[davez.first][davez.second+1] == 0 && G[davez.first][davez.second-1] == 0)    return 1;
        if(G[davez.first+1][davez.second] && !mark[davez.first+1][davez.second]) q.push(make_pair(davez.first+1, davez.second));
        if(G[davez.first-1][davez.second] && !mark[davez.first-1][davez.second]) q.push(make_pair(davez.first-1, davez.second));
        if(G[davez.first][davez.second+1] && !mark[davez.first][davez.second+1]) q.push(make_pair(davez.first, davez.second+1));
        if(G[davez.first][davez.second-1] && !mark[davez.first][davez.second-1]) q.push(make_pair(davez.first, davez.second-1));
    }
    return 1;
}

int main(){
    int jog, auxX, auxY, ans = 0, cont = 0;
    char aux;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            scanf(" %c", &aux);
            if(aux == '#')  G[i][j] = 1;
        }
    scanf("%d", &jog);
    for(int i = 1; i <= jog; ++i){
        scanf("%d %d", &auxY, &auxX);
        if(G[auxY][auxX] == 1){
            G[auxY][auxX] = -1;
            pos[cont].first = auxY;
            pos[cont++].second = auxX;
        }
    }
    for(int i = 0; i < cont; ++i)
        if(!mark[pos[i].first][pos[i].second])
            if(died(pos[i].first,pos[i].second))
                ++ans;

    printf("%d\n", ans);


    return 0;
}
