/*
ID: joaogui1
LANG: C++
TASK: ditch
*/
#include <queue>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#define INF 1 << 29

using namespace std;

vector <int> adj[210];
int cap[210][210], flow_net[210][210];

int main(){
   ios_base::sync_with_stdio(0);
   int n, m, flow, davez, a, b, c, df, v;
   ifstream fin ("ditch.in");
   ofstream fout ("ditch.out");
   fin >> n >> m;
   for(int i = 0; i < n; ++i){
      fin >> a >> b >> c;
      adj[a].push_back(b);
      adj[b].push_back(a);
      cap[a][b] += c;
      //cap[b][a] += c;
   }

   flow = 0;
   queue <int> q;
   while(1){
      int pai[210] = {0};
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
      if(pai[m] == 0)   break;
      df = INF;
      for(int e = m; pai[e] != 0; e = pai[e])
         df = min(df, cap[pai[e]][e] - flow_net[pai[e]][e]);
      //if(df == INF)  break;
      for(int e = m; pai[e] != 0; e = pai[e]){
         flow_net[pai[e]][e] += df;
         flow_net[e][pai[e]] -= df;
      }
      flow += df;
   }
   fout << flow << "\n";
   return 0;
}
