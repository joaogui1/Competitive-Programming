#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

#define MAXN 1000010

//Globais------------------------------
int n;
vector <int> mapa[MAXN];
bool marcado[MAXN];
int maior_distancia, vertice_distante; //auxiliares da dfs "especial"
//-------------------------------------

int liga(int x, int y){
    mapa[x].push_back(y);
    mapa[y].push_back(x);
}

int dfs(int v, int distancia){
    marcado[v]=1;

    if(distancia > maior_distancia){
                 maior_distancia=distancia;
                 vertice_distante=v;
    }

    int nv=mapa[v].size(); //determino número de vizinhos de "v"

    for(int i=0;i<nv;i++){
            if( !marcado[ mapa[v][i] ] )
                dfs(mapa[v][i], distancia+1);
    }
}

int main(){
    int x,y;

    scanf("%d",&n);

    for(int i=1;i<n;i++){
            scanf("%d %d",&x,&y);
            liga(x,y);
    }

    for(int i=1;i<=n;i++) marcado[i]=0;
    dfs(1,0);

    for(int i=1;i<=n;i++) marcado[i]=0;
    dfs(vertice_distante,0);

    printf("%d\n", maior_distancia);

    return 0;
}
