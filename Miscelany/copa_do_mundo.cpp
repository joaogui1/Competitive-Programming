#include <cstdio>
#include <algorithm>
#define MAXN 110
#define MAXM 5010
using namespace std;
struct estrada{
    int x;
    int y;
    int z;
};
int pai[MAXN];
estrada R[MAXM], F[MAXM];
int Find(int x){
    if(x == pai[x]) return x;
    return pai[x] = Find(pai[x]);
}
void Union(int x, int y){
    pai[Find(x)] = Find(y);
}
bool comp(estrada a, estrada b){
    return  a.z < b.z;
}
int main(){
    int n, f, r, a ,b, c, ans = 0, cont = 1;
    scanf("%d %d %d", &n, &f, &r);
    for(int i = 1; i <= n; ++i) pai[i] = i;
    for(int i = 1; i <= f; ++i){
        scanf("%d %d %d", &a, &b, &c);
        F[i].x = a, F[i].y = b, F[i].z = c;
    }
    for(int i = 1; i <= r; ++i){
        scanf("%d %d %d", &a, &b, &c);
        R[i].x = a, R[i].y = b, R[i].z = c;
    }
    sort(F + 1, F + f + 1,  comp);
    for(int i = 1; i <= f; ++i){
        if(Find(F[i].x) != Find(F[i].y)){
            Union(F[i].x, F[i].y);
            ans += F[i].z;
            ++cont;
        }
    }
    if(cont < n){
        sort(R + 1, R + r + 1,  comp);
        for(int i = 1; i <= r; ++i){
            if(Find(R[i].x) != Find(R[i].y)){
                Union(R[i].x, R[i].y);
                ans += R[i].z;
                ++cont;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
