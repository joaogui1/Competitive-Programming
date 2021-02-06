#include <cstdio>
#include <utility>
#include <algorithm>
#define gold() first.first
#define silver() first.second
#define copper() second.first
#define id() second.second
using namespace std;
pair <pair <int, int>, pair< int, int> > countries[110];
int main(){
   int g, s, c, n, m;
   scanf("%d %d", &n, &m);
   for(int i = 1; i <= n; ++i)   countries[i].id() = -i;
   for(int i = 0; i < m; ++i){
      scanf("%d %d %d", &g, &s, &c);
      ++countries[g].gold();++countries[s].silver();++countries[c].copper();
   }
   sort(countries + 1, countries + n + 1);
   for(int i = n; i > 1; --i) printf("%d ", -countries[i].id());
   printf("%d\n", -countries[1].id());
   return 0;
}
