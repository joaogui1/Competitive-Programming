#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#define SET(obj, a) memset(obj, a, sizeof(obj))
#define INF 0x3f3f3f3f
#define gold first
#define silver second.first
#define copper second.second.first
#define id  second.second.second
using namespace std;
vector <pair <int, pair< int, pair<int, int> > > > countries;
int main(){
   int n, m, o, p , b;
   scanf("%d %d", &n, &m);
   for(int i = 1; i <= n; ++i)
      countries.push_back(make_pair(0,make_pair(0, make_pair(0, -i))));
   for(int i = 0; i < m; ++i){
      scanf("%d %d %d", &o, &p, &b);
      ++countries[o-1].gold;
      ++countries[p-1].silver;
      ++countries[b-1].copper;
   }
   sort(countries.begin(), countries.end());
   for(int i = n - 1; i > 0; --i)
       printf("%d ",-countries[i].id);
   printf("%d\n", -countries[0].id);
   return 0;
}
