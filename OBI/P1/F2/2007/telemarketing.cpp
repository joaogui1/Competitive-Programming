#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>
#define SET(obj, a) memset(obj, a, sizeof(obj))
#define INF 0x3f3f3f3f
using namespace std;
priority_queue <pair <int, int> > q;
int tel[1010];
int main(){
   int n, l, t;
   pair <int, int> aux;
   scanf("%d %d", &n, &l);
   for(int i = 1; i <= n; ++i) 
      q.push(pair <int, int>(0, -i));
   for(int i = 0;i < l; ++i) {
      scanf("%d", &t);
      aux = q.top(); q.pop();
      ++tel[-aux.second];
      aux.first -= t;
      q.push(aux);
   }
   for(int i = 1; i <= n; ++i)
      printf("%d %d\n", i, tel[i]);
   return 0;
}
