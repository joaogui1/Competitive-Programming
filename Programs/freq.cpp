#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 1000010
int alun[MAXN];
int main(){
    int m, aux, ans = 0;
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i){
        scanf("%d", &aux);
        if(!alun[aux])
            ans++;
        alun[aux]++;
    }
    printf("%d\n", ans);



    return 0;
}

