#include <set>
#include <cstdio>
#include <cstdlib>
using namespace std;
bool can[1 << 19];
int main(){
   int v, m, aux;
   scanf("%d %d", &v, &m);
   can[0] = 1;
   for(int i = 0; i < m; ++i){
      scanf("%d", &aux);
      for(int j = v; j >= aux; --j)
         if(can[j - aux])  can[j] = 1;
   }
   printf("%s\n",(can[v])?"S":"N");
   return 0;
}
