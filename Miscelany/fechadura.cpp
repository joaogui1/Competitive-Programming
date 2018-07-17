#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN 1010
#define MAXM 5010
using namespace std;
int pinos[MAXN];
int main(){
    int n, m, delta, ans = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &pinos[i]);
    for(int i = 1; i <= n; ++i){
        delta = m - pinos[i];
        if(pinos[i + 1] + delta == m)    ++i;
        else    pinos[i + 1] += delta;
        ans += abs(delta);
    }
    printf("%d\n", ans);
    return 0;
}


