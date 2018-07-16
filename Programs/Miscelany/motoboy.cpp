#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
struct pedido{
    int num;
    int temp;
};
pedido pedidos[40];
int G[40][40], n;
int knapsack(int i, int ped){
    if(i > n)  return 0;
    if(G[i][ped] > 0) return G[i][ped];
    if(ped < pedidos[i].num)
        return G[i][ped] = knapsack(i + 1, ped);
    return G[i][ped] = max(knapsack(i + 1, ped), knapsack(i + 1, ped - pedidos[i].num) + pedidos[i].temp);
}
int main(){
    int p;
    while(1){
        scanf("%d", &n);
        if(!n)   break;
        scanf("%d", &p);
        memset(G, 0, sizeof(G));
        for(int i = 1; i <= n; ++i)
            scanf("%d %d", &pedidos[i].temp, &pedidos[i].num);
        int ans = knapsack(1, p);
        printf("%d min.\n", ans);
    }



    return 0;
}

