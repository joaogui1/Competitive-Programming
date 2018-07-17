#include <queue>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <iostream>
using namespace std;
priority_queue <pair <int, int> > q;
int ans[1010];
int main(){
   int t, n, l;
   pair <int, int> aux;
   scanf("%d%d", &n, &l);
   for(int i = 1; i <= n; ++i)
      q.push(make_pair(0, -i));
   for(int i = 0; i < l; ++i){
      scanf("%d", &t);
      aux = q.top();q.pop();
      ++ans[-aux.second];
      aux.first -= t;
      q.push(aux);
   }
   for(int i = 1; i <= n; ++i)
      printf("%d %d\n", i, ans[i]);
   return 0;
}
