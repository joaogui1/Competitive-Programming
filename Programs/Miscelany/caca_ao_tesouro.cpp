#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>
#define MAXN 110
using namespace std;
int G[MAXN][MAXN], mark[MAXN][MAXN];
int main(){
    int n, k, a, b, c, ansx = -1, ansy = -1;
    bool ind = 0;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= k; ++i){
        scanf("%d %d %d", &a, &b, &c);
        for(int j = 0; j < n; ++j)
            for(int q = 0; q < n; ++q)
                if(abs(j - a) + abs(q - b) == c)
                    ++mark[j][q];
    }
    for(int i = 0; i < n && !ind; ++i)
        for(int j = 0; j < n && !ind; ++j){
            if(mark[j][i] == k && ansx == -1 ){
                ansx = j, ansy = i;
            }
            else if(mark[j][i] == k && ansx != -1){
                ansx = -1, ansy = -1;
                ind = 1;
            }
        }
    printf("%d %d\n", ansx, ansy);
    return 0;
}
