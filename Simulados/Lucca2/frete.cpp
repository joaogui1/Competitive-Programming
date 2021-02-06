#include <cstdio>
#include <utility>
#include <algorithm>
#include <iostream>
#define COST first
#define X second.first
#define Y second.second
using namespace std;
int pai[1100];
pair <int, pair<int, int> > arestas[10100];
int find(int x){
   if(x == pai[x])   return x;
   else  return pai[x] = find(pai[x]);
}
void join(int x, int y){
   x = find(x); y = find(y);
   pai[x] = y;
}
int main(){
   int n, m, p, q, u, ans = 0;
   pair <int, pair <int, int> > aux;
   scanf("%d %d", &n, &m);
   for(int i = 0; i < n; ++i)
      pai[i] = i;
   for(int i = 0; i < m; ++i)
      scanf("%d %d %d", &arestas[i].X, &arestas[i].Y , &arestas[i].COST);
   sort(arestas, arestas + m);
   for(int i = 0; i < m; ++i){
      //cout << arestas[i].X << " " << arestas[i].Y  << " " << arestas[i].COST << endl;
      //cout << "   " << find(arestas[i].X) << " " << find(arestas[i].Y) << endl;
      if(find(arestas[i].X) != find(arestas[i].Y)){
         //cout << "joined" << endl;
         join(arestas[i].X, arestas[i].Y);
         ans += arestas[i].COST;
      }
   }
   printf("%d\n", ans);

   return 0;
}
