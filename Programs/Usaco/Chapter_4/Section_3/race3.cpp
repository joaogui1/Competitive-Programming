/*
ID: joaogui1
LANG: C++
TASK: race3
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int mark[60], pai[60];
vector <int> adj[60], rev_adj[60], una, split;

void dfs(int x, int lim){
   mark[x] = 1;
   if(x == lim)   return;
   for(int i = 0; i < int(adj[x].size()); ++i)
      if(!mark[adj[x][i]]){
         ++mark[adj[x][i]];
         pai[adj[x][i]] = x;
         dfs(adj[x][i], lim);
      }
   return;
}

void dfs_rev(int x, int lim){
   mark[x] = 1;
   if(x == lim)   return;
   for(int i = 0; i < int(rev_adj[x].size()); ++i)
      if(!mark[rev_adj[x][i]]){
         ++mark[rev_adj[x][i]];
         pai[rev_adj[x][i]] = 0;
         dfs_rev(rev_adj[x][i], lim);
      }
   return;
}

int main(){
   ios_base::sync_with_stdio(0);
   int n = 0, m, aux;
   bool aub;
   ifstream fin ("race3.in");
   ofstream fout ("race3.out");
   while(1){ //parte 1, leitura
      fin >> aux;
      if(aux == -1)  break;
      if(aux == -2){
         ++n;
         continue;
      }
      adj[n].push_back(aux);
      rev_adj[aux].push_back(n);
      ++m;
   }
   for(int i = 1; i < n - 1; ++i){ //parte 2, unavoidable
      mark[i] = 1;
      dfs(0, n);
      if(!mark[n - 1])   una.push_back(i);
      for(int i = 1; i <= n; ++i)   mark[i] = 0;
   }

   fout << una.size();
   for(int i = 0; i < int(una.size()); ++i)  fout << " " << una[i];
   fout << "\n";

   memset(mark, 0, sizeof(mark));

   for(int i = 0; i < int(una.size()); ++i){
      dfs(0, una[i]);
      for(int j = 0; j <= n; ++j)   mark[j] = 0;
      for(int j = i; pai[j] != 0; j = pai[j])
         mark[j] = 1;
      aub = 1;
      for(int j = 0; j <= n; ++j)   pai[j] = 0;
      dfs(una[i], n - 1);
      for(int j = n - 1; pai[j] != una[i]; j = pai[j])
         aub &= mark[j];
      for(int j = 0; j <= n; ++j)   mark[j] = 0;
      pai[n - 1] = 0;
      dfs_rev(n - 1, una[i]);
      for(int j = 0; j < n; ++j)
         aub &= !pai[j];

      if(aub)  split.push_back(una[i]);
      //fazer dfs(i) e checar se chega em cada ponto depois dele
      //fazer rev_dfs
   }

   fout << split.size();
   for(int i = 0; i < int(split.size()); ++i)  fout << " " << split[i];
   fout << "\n";

   return 0;
}
