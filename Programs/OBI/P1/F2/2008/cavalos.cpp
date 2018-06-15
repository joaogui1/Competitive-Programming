#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define SET(obj, a) memset(obj, a, sizeof(obj))
#define INF 0x3f3f3f3f
using namespace std;

int main(){
   int n, m, ans;
   scanf("%d %d", &n, &m);
   if(m == 1 || n == 1) ans = m*n;
   else if(m > 2 && n > 2) ans = (m*n + 1)/2;
   else{
      n = max(m,n);m = 2;
      if(n%4 == 0)   ans = n;
      if(n%4 == 2)   ans = n + 2;
      else  ans = n + 1;
   }
   printf("%d\n",ans);
}
