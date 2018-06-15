#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 110
#define MAXM 5010
using namespace std;
int tab[MAXN][MAXN];
int main(){
    int n, maior = 0, current = 0;
    char esp;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            scanf(" %c", &esp);
            if(esp == 'o')  tab[j][i] = 1;
            else if(esp == 'A') tab[j][i] = -1;
        }
    for(int i = 1; i <= n; ++i){
        if(i%2 == 1)
            for(int j = 1; j <= n; ++j){
                if(tab[j][i] == 1)  ++current;
                else if(tab[j][i] == -1)    current = 0;
                if(current > maior) maior = current;
            }
        else
            for(int j = n; j > 0; --j){
                if(tab[j][i] == 1)  ++current;
                else if(tab[j][i] == -1)    current = 0;
                if(current > maior) maior = current;
            }
    }
    printf("%d\n", maior);
    return 0;
}


