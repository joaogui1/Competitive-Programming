#include <cstdio>
#include <utility>
#include <algorithm>
#define MAXN 1010
using namespace std;
int temp_caixa[20], beg, end;
pair <int, int> q[MAXN];
void push_back(int x, int y){
    q[++end].first = x;
    q[end].second = y;
    return;
}
pair <int, int> pop(){
    return q[beg++];
}
int main(){
    int c, n, aux, auy, ans = 0;
    end = -1;
    pair <int, int> davez;
    scanf("%d %d", &c, &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d %d", &aux, &auy);
        push_back(aux , auy);
    }
    while(beg < n){
            davez = pop();
            if(temp_caixa[1] < davez.first) temp_caixa[1] = davez.first;
            if(temp_caixa[1] - davez.first > 20 && beg <= n){
                ++ans;
            }
            temp_caixa[1] += davez.second;
        sort(temp_caixa + 1, temp_caixa + c + 1);
    }
    printf("%d\n", ans);


    return 0;
}
