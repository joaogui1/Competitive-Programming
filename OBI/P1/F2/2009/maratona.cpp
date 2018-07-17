#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define SET(obj, a) memset(obj, a, sizeof(obj))
#define INF 0x3f3f3f3f
using namespace std;

int main(){
   int n, m, ans = 1, old, New = 0;
   scanf("%d %d", &n, &m);
   for(int i = 0; i < n; ++i){
      old = New;
      scanf("%d", &New);
      if(New - old > m) ans = 0;
   }
   if(42195 - New > m)  ans = 0;
   if(ans)  printf("S\n");
   else  printf("N\n");
}
