#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 510
#define MAXM 5010
using namespace std;
int matriz[MAXN][MAXN];

int main(){
    int n, m, cont = 0;
    bool shit = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d", &matriz[j][i]);
    for(int i = 1; i <= n && !shit; ++i){
        if(cont == 0)
            for(int j = 1; j <= m && !shit; ++j){
                if(matriz[j][i] != 0){
                    cont = 0;
                    for(int k = i + 1; k <= n; ++k){
                        if(matriz[j][k] != 0){
                            shit = 1;
                            break;
                        }
                    }
                    break;
                }
                else cont++;
            }
        else
            for(int j = 1; j <= m && !shit; ++j)
                if(matriz[j][i] != 0)   shit = 1;

    }
        if(shit)    printf("N\n");
        else    printf("S\n");
    return 0;
}


