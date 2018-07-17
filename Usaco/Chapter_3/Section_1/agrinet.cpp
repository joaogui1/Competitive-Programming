/*
ID: joaogui1
LANG: C++
TASK: agrinet
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
int pai[110];
vector <pair <int, pair <int, int> > > edges;

int find(int x){
   return (x == pai[x])?x:pai[x] = find(pai[x]);
}

void join(int x, int y){
   pai[find(x)] = find(y);
   return;
}

int main(){
   int n, aux, ans = 0;
   ifstream fin ("agrinet.in");
   ofstream fout ("agrinet.out");
   fin >> n;
   for(int i = 1; i <= n; ++i)   pai[i] = i;
   for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j){
         fin >> aux;
         edges.push_back(make_pair(aux, make_pair(i, j)));
      }
   sort(edges.begin(), edges.end());
   for(int i = 0; i < n*n; ++i){
      if(find(edges[i].second.first) != find(edges[i].second.second)){
         join(edges[i].second.first, edges[i].second.second);
         ans += edges[i].first;
      }
   }
   fout << ans << endl;
   return 0;
}
