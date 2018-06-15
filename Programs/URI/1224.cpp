#include <cstdio>
#include <algorithm>
#define MAXN 10010

using namespace std;

long long  c[MAXN], opt[MAXN][3];

int main(){
   int n;
   while(scanf("%d", &n) != -1){
      for(int i = 1; i <= n; ++i){
         scanf("%lld", &c[i]);
      }
      for(int j = 1; j <= n; ++j){
         for(int i = j; i > 0; --i){
            if(i == j)  opt[i][j % 3] = c[i];
            else if (i + 1 == j) opt[i][j % 3] = max(c[i], c[j]);
            else  opt[i][j % 3] = max(min(opt[i + 2][j % 3], opt[i + 1][(j - 1) % 3]) + c[i], min(opt[i + 1][(j - 1) % 3], opt[i][(j - 2) % 3]) + c[j]);
         }
      }
      printf("%lld\n", opt[1][n % 3]);
   }
   return 0;
}
