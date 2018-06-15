/*
ID: joaogui1
LANG: C++
TASK: fence6
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#define INF 1 << 28

using namespace std;

int G[110][110];

void fw(int n){
   //for(int i = 1; i <= n; ++i)   G[i][i] = 0;
   for(int k = 1; k <= n; ++k)
      for(int i = 1; i <= n; ++i)
         for(int j = 1; j <= n; ++j)
            G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

   return;
}
int main(){
   ios_base::sync_with_stdio(0);
   int n, n1, n2, s, l, aux, ans = INF;
   ifstream fin ("fence6.in");
   ofstream fout ("fence6.out");
   fin >> n;
   for(int i = 0; i <= n; ++i)
      for(int j = 0; j <= n; ++j)   G[i][j] = INF;
   for(int i = 1; i <= n; ++i){
      fin >> s >> l >> n1 >> n2;
      for(int j = 0; j < n1; ++j){
         fin >> aux;
         G[aux][s] = l;
      }
      for(int j = 0; j < n2; ++j){
         fin >> aux;
         G[s][aux] = l;
      }
   }
   fw(n);

   for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= n; ++j)   cout << G[i][j] << " ";
      cout << endl;
   }

   /*for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
         if(i != j)  ans = min(ans, G[i][j] + G[j][i]);*/
   for(int i = 1; i <= n; ++i)   ans = min(ans, G[i][i]);
   fout << ans << "\n";
   return 0;
}
