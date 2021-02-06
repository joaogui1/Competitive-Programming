#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAXL 17
#define MAXN 100100
#define SET(obj, a)  memset(obj, a, sizeof(obj));
#define INF 1 << 30
#define pii pair <long long int, long long int>

using namespace std;

int nivel[MAXN], v;
pii pai[MAXN], ancestral[MAXN][MAXL];
vector <pii> edges[MAXN];

void initialize(){
   SET(nivel, -1);
   SET(edges, 0LL);
   SET(ancestral, -1LL);
   SET(pai, -1LL);
   return;
}

void dfs(int x){
   for(int i = 0; i < edges[x].size(); ++i){
      v = edges[x][i].first;
      if(nivel[v] == -1){
         pai[v].first = x;
         pai[v].second = edges[x][i].second;
         nivel[v] = nivel[x] + 1;
         dfs(v);
      }
   }
}

long long int LCA(int u, int v){
   long long int ret = 0;
   if(nivel[u] < nivel[v]) swap(u, v);

   for(int i = MAXL - 1; i >= 0; --i)
      if(nivel[u] - (1 << i) >= nivel[v])
         ret += ancestral[u][i].second, u = ancestral[u][i].first;
   if(u == v)  return ret;

   for(int i = MAXL - 1; i >= 0; --i)
      if(ancestral[u][i].first != -1 && ancestral[u][i].first != ancestral[v][i].first){
         ret += (ancestral[u][i].second + ancestral[v][i].second);
         u = ancestral[u][i].first;
         v = ancestral[v][i].first;
      }
   ret += (pai[u].second + pai[v].second);
   return ret;
}
int main(){
   int n, q, a, b;
   long long int ai, li;

   while(scanf("%d", &n) && n){
      initialize();
      for(int i = 1; i < n; ++i){
         scanf("%lld %lld", &ai, &li);
         edges[i].push_back(pii(ai, li));
         edges[ai].push_back(pii(i, li));
      }
      nivel[0] = pai[0].first = pai[0].second = 0;
      dfs(0);
      for(int i = 0; i < n; ++i)   ancestral[i][0].first = pai[i].first, ancestral[i][0].second = pai[i].second;
      for(int j = 1; j < MAXL; ++j)
         for(int i = 0; i < n; ++i){
            ancestral[i][j].first = ancestral[ancestral[i][j - 1].first][j - 1].first;
            ancestral[i][j].second = ancestral[ancestral[i][j - 1].first][j - 1].second + ancestral[i][j - 1].second;
         }
      scanf("%d", &q);
      while(q--){
         scanf("%d %d", &a, &b);
         printf("%lld", LCA(a, b));
         if(q) printf(" ");
      }
      printf("\n");
   }


   return 0;
}
