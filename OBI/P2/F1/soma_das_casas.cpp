#include <cstdio>
#include <utility>
#include <algorithm>
#define MAXN 100010
using namespace std;
int casas[MAXN], n;
int bin_search(int x){
    int ini = 1, meio, fim = n;
    while(ini <= fim){
        meio = (ini + fim)/2;
        if(casas[meio] == x)    return casas[meio];
        if(casas[meio] < x)    ini = meio + 1;
        if(casas[meio] > x)    fim = meio - 1;
    }
    return -1;
}
int main(){
    int k, ans1, ans2;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &casas[i]);
    scanf("%d", &k);
    for(int i = 1; i <= n; ++i)
        casas[i]++;
    k+=2;
    for(int i = 1; i <= n; ++i){
        ans1 = casas[i];
        ans2 = bin_search(k - ans1);
        if(ans2 != -1)  break;
    }
    ans1--;ans2--;
    printf("%d %d\n", ans1, ans2);
    return 0;
}
