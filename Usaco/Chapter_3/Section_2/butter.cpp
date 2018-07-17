/*
ID: joaogui1
LANG: C++
TASK: butter
*/
#include <queue>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
//----------------------x---------------------------
typedef pair <int, int> pii;
#define ff first
#define ss second
#define INF 1 << 28
//----------------------x---------------------------

int cows[600], dist[850], n;
vector <pii> pastures[850];

int djikstra(int x){
   priority_queue<pii, vector<pii>, greater<pii> > pq; //fazer uma min-heap
   int davez, menor = INF;

   for(int i = 0; i < 850; ++i) dist[i] = INF;
   dist[x] = 0;
   pq.push(pii(0, x));

   while(1){
      davez = -1, menor = INF;
      while(pq.size()){
         int d = pq.top().ff;
         int v = pq.top().ss;
         pq.pop();
         if(dist[v] != d)  continue;
         davez = v;
         break;
      }
      if(davez == -1)   break;

      for(int i = 0; i < (int)pastures[davez].size(); ++i){
         int v = pastures[davez][i].ss;
         int d = pastures[davez][i].ff;
         if(dist[v] > dist[davez] + d){
            dist[v] = dist[davez] + d;
            pq.push(pii(dist[v], v));
         }
      }
   }

   int ret = 0;
   for(int i = 1; i <= n; ++i)   ret += dist[cows[i]];
   return ret;
}

int main(){
   ios_base::sync_with_stdio(0);
   //cout << "ok\n";
   int ans, p, c, test, a, b, d;
   ans = 1 << 30;
   ifstream fin ("butter.in");
   ofstream fout ("butter.out");
   fin >> n >> p >> c;
   //cout << "ok\n";
   for(int i = 1; i <= n; ++i)   fin >> cows[i];
   for(int i = 0; i < c; ++i){
      fin >> a >> b >> d;
      pastures[a].push_back(pii(d, b));
      pastures[b].push_back(pii(d, a));
   }
   //cout << "ok\n";
   for(int i = 1; i <= p; ++i){
      //cout << "ok\n";
      test = djikstra(i);
      if(test > 0 && test < ans) ans = test;
   }
   fout << ans << endl;

   return 0;
}
