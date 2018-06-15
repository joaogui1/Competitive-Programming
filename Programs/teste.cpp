#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXN 110
using namespace std;
pair <int, int> pos[MAXN];
int n, m, G[MAXN][MAXN], mark[MAXN][MAXN];

int main(){
    int n;
    scanf("%d", &n);
    printf("%d %d\n", n, n);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j)
            printf("#");
        printf("\n");
        }
    printf("%d\n", n*n);
     for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j)
            printf("%d %d ", i, j);
        printf("\n");
        }

    return 0;
}

