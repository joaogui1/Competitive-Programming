#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define MAXN 1010
#define MOD 1000000007
long long int tab[MAXN][MAXN], B, G;
long long int DP(int b, int g){
    if(b < g || g < 0 || b < 0) return 0;
    if(g == 1 || b == 1)  return 1;
    if(tab[b][g] > 0)   return tab[b][g];
    return tab[b][g] = (DP(b-1,g)*g + DP(b-1,g-1)*g)%(MOD) ;

}
int main(){
    tab[1][1] = 1;
    for(int i = 2; i < MAXN; ++i){
        tab[i][i] = (tab[i-1][i-1]*i)%MOD;
    }
    while(1){
        scanf("%lld %lld", &B, &G);
        if(B == 0 && G == 0)    break;
        long long int ans = DP(B, G);
        printf("%lld\n", ans);
    }



    return 0;
}

