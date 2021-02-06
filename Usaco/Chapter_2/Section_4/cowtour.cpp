/*
ID: joaogui1
LANG: C++
TASK: cowtour
*/
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <utility>
#include <iostream>
#include <algorithm>
#define debug(a, b, c, d ,e)  std::cout << a << " " << b << " " << c << " " << d << " " << e
#define INF (1 << 30) + 0.1
using namespace std;
int n,v[160][5], mark[160];
double dist[160][160], w[160][160];
double hyp(int i, int j){
   return sqrt((v[i][1] - v[j][1])*(v[i][1] - v[j][1]) + (v[i][2] - v[j][2])*(v[i][2] - v[j][2]));
}
void dfs(int x, int m){
   mark[x] = m;
   for(int i = 1; i <= n; ++i){
      if(!mark[i] && w[i][x] >= 0.5) dfs(i, m);
   }
}
void fw(){
   for(int k = 1; k <= n; ++k)
      for(int i = 1; i <= n; ++i)
         for(int j = 1; j <= n; ++j)
            if(dist[i][j] > dist[i][k] + dist[k][j])  dist[i][j] = dist[i][k] + dist[k][j];
}
int main(){
   int aux, cont = 0;
   string aux_s;
   double ans = INF;
   ifstream fin("cowtour.in");
   FILE *fout = fopen ("cowtour.out", "w");
   fin >> n;
   for(int i = 1; i <= n; ++i)
      fin >> v[i][1] >> v[i][2];
   for(int i = 1; i <= n; ++i){
      fin >> aux_s;
      for(int j = 0; j < n; ++j){
         aux = aux_s[j] - '0';
         if(aux == 1){
               w[i][j + 1] = hyp(i,j + 1);
         }
      }
   }
   for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j){
         if(w[i][j] != 0)  dist[i][j] = w[i][j];
         if(i != j && w[i][j] == 0) dist[i][j] = INF;
      }
   for(int i = 1; i <= n; ++i)   if(!mark[i])   dfs(i, ++cont);
   fw();
   for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j){
         if(dist[i][j] > dist[i][0] && mark[i] == mark[j])   dist[i][0] = dist[j][i];
   }
   for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= n; ++j)
         if(i != j && mark[i] != mark[j] && hyp(i, j) + dist[i][0] + dist[j][0] < ans) ans = hyp(i, j) + dist[i][0] + dist[j][0];
   }
   for(int i = 1; i <= n; ++i)   if(dist[i][0] > ans) ans = dist[i][0];
   fprintf(fout, "%0.6lf\n", ans);
   return 0;
}
