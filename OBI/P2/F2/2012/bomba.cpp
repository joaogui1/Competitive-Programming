#include <queue>
#include <cstdio>
#include <algorithm>
#define MAXN 510
using namespace std;
int G[MAXN][MAXN][5], dist[MAXN][5], N, S;
queue <int> q;
void BFS(int v){
    q.push(v);
    dist[v][0] = 1;
    while(!q.empty() && q.front() != S){
        int davez = q.front();q.pop();
        for(int j = 0; j < 3; ++j){
            if(dist[davez][j]){ // diz por onde entrei
                for(int i = 0; i < N; ++i){
                    if(G[davez][i][j] && !dist[i][(j + 1)%3]){ //checa se davez estah ligado com i no tempo j mod 3 e se a distancia ainda nao foi definida
                        G[davez][i][j] = 0; // remove a lligacao para que davez nao passe de novo por i no tempo j mod 3
                        q.push(i); //adiciona i na fila
                        dist[i][(j+1)%3] = dist[davez][j] + 1;
                    }
                }
            }
        }
    }
    return;
}
int main(){
    int E, M, A, B, T;
    scanf("%d %d %d %d", &N, &E, &S, &M);
    for(int i = 1; i <= M; ++i){
        scanf("%d %d %d", &A, &B, &T);
        if(T)
            G[A][B][0] = 1;
        else{
            G[A][B][1] = 1;
            G[A][B][2] = 1;
        }
    }
    BFS(E);
    sort(dist[S], dist[S] + 3);
    if(dist[S][0] != 0) printf("%d\n", dist[S][0] - 1);
    else if(dist[S][1] != 0) printf("%d\n", dist[S][1] - 1);
    else if(dist[S][2] != 0) printf("%d\n", dist[S][2] - 1);
    else    printf("*\n");
    return 0;
}
