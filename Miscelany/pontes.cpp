#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 10010
using namespace std;
int G[MAXN], alc[MAXN];
int b, r, a, c;
int main(){
    while(scanf("%d%d", &r, &b) != EOF){
        int maxind = 0;
        bool vdc;
        memset(G, 0, sizeof(G));
        memset(alc, 0, sizeof(alc));
        for(int i = 0; i < b; ++i){
            scanf("%d%d", &a,&c);
            ++G[a];++G[c];
        }
        alc[0] = 1;
        for(int i = 0; i < r; ++i){
            for(int j = maxind ; j >= 0; --j){
                if(alc[j] == 1)
                    alc[j + G[i]] = 1;
            }
            maxind += G[i];
        }
        if(alc[b]) printf("S\n");
        else printf("N\n");
    }
    return 0;
}
