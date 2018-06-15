#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#define debug(a, b, c, d ,e)  std::cout << a << " " << b << " " << c << " " << d << " " << e
#define INF (1 << 30)
#define SET(obj, a) memset(obj, a, sizeof(obj))
using namespace std;
int pai[MAXN], dist[MAXN];

int find(int x){
   if(pai[x] == pai[pai[x]])   return dist[x];
   else{
      pai[x] = find(pai[x]);
      dist[x] += dist[pai[x]];
      return pai[x];
      }
   }
void join(int x, int y){
   if(x == pai[x]){
      pai[x] = find(y);
      dist[x] = abs(x - y) + dist(y);
   }
}
int main(){




   return 0;

}
