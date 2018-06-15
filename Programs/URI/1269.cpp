#include <bits/stdc++.h>

using namespace std;

int value[1010];
bool trabs[1010][1010];
vector <int> toposort, depend[1010], adj[1010], works_in[1010];

void init(){
   cout << "*****\n";
   memset(value, 0, sizeof value);
   memset(trabs, 0, sizeof trabs);
   toposort.clear();
   for(int i = 0; i < 1010; ++i){
      works_in[i].clear();
      depend[i].clear();
      adj[i].clear();
      adj[i].push_back(0);
   }
   return;
}

void _read(int t, int e){
   int nt, ne, aux;
   for(int i = 0; i < e; ++i){
      cin >> value[i] >> nt >> ne;
      for(int j = 0; j < nt; ++j){
         cin >> aux;
         depend[i].push_back(aux);
         ++adj[aux][0];
         adj[aux].push_back(i);
      }

      for(int j = 0; j < ne; ++j){
         cin >> aux;
         works_in.push_back(aux);
      }
   }
   return;
}

void topological(){

   return;
}

int main(){
   ios_base::sync_with_stdio(0);
   int t, e;
   while(cin >> t >> e){
      if(t + e < 1)  return 0;
      init();
      _read(t, e);
      topological();
   }

   return 0;
}
