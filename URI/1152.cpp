#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int pai[200010];

int find(int x){
   return (pai[x] == x)?x:(pai[x] = find(pai[x]));
}

int join(int x, int y){
   return pai[find(x)] = pai[find(y)];
}

int main(){
   ios_base::sync_with_stdio(0);
   int n, m, x, y, z, num;
   long long int sum, cost;
   while(1){
      sum = cost = num = 0;
      cin >> m >> n;
      if(n == 0 && m == 0) return 0;
      for(int i = 0; i <= m; ++i)   pai[i] = i;
      vector <pair <int, pair <int, int> > > edges;
      for(int i = 0; i < n; ++i){
         cin >> x >> y >> z;
         edges.push_back(make_pair(z, make_pair(x, y)));
         sum += z;
      }
      sort(edges.begin(), edges.end());
      for(int i = 0; i < n; ++i){
         if(find(edges[i].second.first) != find(edges[i].second.second)){
            cost += edges[i].first;
            join(edges[i].second.first, edges[i].second.second);
            ++num;
         }
         //if(num == m - 1)  break;
      }
      cout << sum - cost << "\n";
   }


   return 0;
}
