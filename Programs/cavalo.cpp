#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 1000010
int dx[9] = {0, 1, 2, 2, 1, -1, -2 ,-2, -1}, dy[9] = {0, 2, 1, -1, -2, -2 , -1, 1, 2};
int main(){
    int n, m, posx = 4, posy = 3, i;
    scanf("%d", &n);
    for(i = 1; i <= n; ++i){
        scanf("%d", &m);
        posx += dx[m];
        posy += dy[m];
        if(posx == 1 && posy == 3)  break;
        if(posx == 2 && posy == 3)  break;
        if(posx == 2 && posy == 5)  break;
        if(posx == 5 && posy == 4)  break;
    }
    if(i > n)   i = n;
    printf("%d\n", i);


    return 0;
}


