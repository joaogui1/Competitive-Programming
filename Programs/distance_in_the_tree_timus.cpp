#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//Defines:
#define MAXL 21
#define MAXN 50100
typedef pair<int, int> pii;
//--------------------------------------------------------------------



int level[MAXN], v, ret;
pii pai[MAXN], ancestral[MAXN][MAXL + 1];
vector <pii> edges[MAXN];

void initialize(){
   for(int i = 1; i < MAXN; ++i)   level[i] = -1;

   for(int j = 0; j < MAXL; ++j)
      for(int i = 0; i < MAXN; ++i)
         ancestral[i][j].first = -1;

   for(int i = 0; i < MAXN; ++i) pai[i].first = -1;
}

void dfs(int x){
   for(int i = 0; i < edges[x].size(); ++i){
      v = edges[x][i].first;
      if(level[v] == -1){
         level[v] = level[x] + 1;
         pai[v] = pii(x, edges[x][i].second);
         dfs(v);
      }
   }
   return;
}

int lca(int u, int v){
   ret = 0;
   if(level[u] < level[v]) swap(u, v);
   for(int i = MAXL - 1; i >= 0; --i)
      if(level[u] - (1 << i) >= level[v]){
         ret += ancestral[u][i].second;
         u = ancestral[u][i].first;
      }
   if(u == v)  return ret;
   for(int i = MAXL - 1; i >= 0; --i){
      if(ancestral[u][i].first != -1 && ancestral[u][i].first != ancestral[v][i].first){
         ret += (ancestral[u][i].second + ancestral[v][i].second);
         u = ancestral[u][i].first;
         v = ancestral[v][i].first;
      }
   }
   ret += (pai[u].second + pai[v].second);

   return ret;


}

int main(){
   int n, u, v, w, q;
   initialize();
   scanf("%d", &n);
   for(int i = 1; i < n; ++i){
      scanf("%d %d %d", &u, &v, &w);
      edges[u].push_back(pii(v, w));
      edges[v].push_back(pii(u, w));
   }
   //pai[0] = pii(0, 0);
   dfs(0);
   for(int i = 0; i < n; ++i) ancestral[i][0] = pai[i];

   for(int j = 1; j < MAXL; ++j)
      for(int i = 0; i < n; ++i){
         ancestral[i][j].first = ancestral[ancestral[i][j - 1].first][j - 1].first;
         ancestral[i][j].second = ancestral[ancestral[i][j - 1].first][j - 1].second + ancestral[i][j - 1].second;
      }
   
   scanf("%d", &q);

   for(int i = 0; i < q; ++i){
      scanf("%d %d", &u, &v);
      printf("%d\n", lca(u, v));
   }

   return 0;

}
