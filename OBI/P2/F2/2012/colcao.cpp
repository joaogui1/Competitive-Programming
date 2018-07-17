#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int colcao[5], porta[3];
int main(){
    scanf("%d %d %d %d %d", &colcao[1], &colcao[2], &colcao[3], &porta[1], &porta[2]);
    sort(colcao + 1, colcao + 4);
    sort(porta + 1, porta + 3);
    if(colcao[1] <= porta[1] && colcao[2] <= porta[2])    printf("S\n");
    else printf("N\n");



    return 0;
}
