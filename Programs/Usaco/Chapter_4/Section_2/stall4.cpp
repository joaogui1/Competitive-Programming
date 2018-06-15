/*
ID: joaogui1
LANG: C++
TASK: stall4
*/
#include <queue>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#define INF 1 << 29

using namespace std;

vector <int> adj[410];
int cap[410][410], flow_net[410][410];

int main(){
   ios_base::sync_with_stdio(0);
   int n, m, flow, davez, a, b, c, df, v;
   ifstream fin ("stall4.in");
   ofstream fout ("stall4.out");
   fin >> n >> m;
   ++n;
   for(int i = 2; i <= n ; ++i){
      fin >> a;
      for(int j = 0; j < a; ++j){
         fin >> b;
         adj[i].push_back(b + n);
         adj[b + n].push_back(i);
         cap[i][b + n] = 1;
      }
   }
   for(int i = 2; i <= n; ++i){
      adj[1].push_back(i);
      adj[i].push_back(1);
      cap[1][i] = 1;
   }

   for(int i = 1; i <= m; ++i){
      adj[n + m + 1].push_back(i + n);
      adj[n + i].push_back(n + m + 1);
      cap[n + i][n + m + 1] = 1;
   }

   flow = 0;
   queue <int> q;
   while(1){
      int pai[410] = {0};
      q.push(1);
      while(q.size()){
         davez = q.front();q.pop();
         for(int i = 0; i < int(adj[davez].size()); ++i){
            v = adj[davez][i];
            if(pai[v] == 0 && v != 1 && cap[davez][v] - flow_net[davez][v] > 0){
               pai[v] = davez;
               q.push(v);
            }
         }
      }
      if(pai[m + n + 1] == 0)   break;
      df = INF;
      for(int e = m + n + 1; pai[e] != 0; e = pai[e])
         df = min(df, cap[pai[e]][e] - flow_net[pai[e]][e]);

      if(df == INF)  break;
      for(int e = m + n + 1; pai[e] != 0; e = pai[e]){
         flow_net[pai[e]][e] += df;
         flow_net[e][pai[e]] -= df;
      }
      flow += df;
   }
   fout << flow << "\n";
   return 0;
}
