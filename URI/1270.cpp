#include <bits/stdc++.h>

using namespace std;

int mark[1010];
double dp[1010][60];
map <int, pair<double, double > >cart;
map <string, int> cities;
vector<int> adj[1010], child[1010], rot[1010];

double dist(int id1, int id2){
   return sqrt((cart[id1].first - cart[id2].first)*(cart[id1].first - cart[id2].first) + (cart[id1].second - cart[id2].second)*(cart[id1].second - cart[id2].second));
}

void dfs(int x){
   ++mark[x];
   for(int i = 0; i < adj[x].size(); ++i)
      if(!mark[adj[x][i]]){
         child[x].push_back(adj[x][i]);
         dfs(adj[x][i]);
      }
   return;
}

double solve(int x, int c){
   if(dp[x][c] != 0) return dp[x][c];
   if(child[x].size() == 0)   return 0;

   int v;
   double ans = 0.0, best;
   for(int i = 0; i < child[x].size(); ++i){
      best = (1 << 30) + 0.5;
      v = child[x][i];
      for(int j = 0; j < rot[v].size(); ++j)
         best = min(best, solve(v, j) + dist(rot[x][c], rot[v][j]));
      ans += best;
   }
   return dp[x][c] = ans;
}

double solve(int x){
   double ans = (1 << 30) + 0.5;
   for(int i = 0; i < rot[x].size(); ++i)
      ans = min(ans, solve(x, rot[x][i]));
   return ans;
}

void init(){
   memset(mark, 0, sizeof mark);
   memset(dp, 0, sizeof dp);
   cities.clear();
   cart.clear();
   for(int i = 0; i < 1010; ++i){
      adj[i].clear();
      rot[i].clear();
      child[i].clear();
   }
}

int main(){
   ios_base::sync_with_stdio(0);
   cout.precision(1);
   cout.setf(ios::fixed);
   int n, c, cont;
   double aux, auy;
   string aua, aub;
   while(cin >> n){
      if(n == 0)   return 0;
      cont = 0;
      init();
      for(int i = 1; i <= n; ++i){
         cin >> aua;
         cities[aua] = i;
         cin >> c;

         for(int j = 0; j < c; ++j){
            cin >> aux >> auy;
            rot[i].push_back(cont);
            cart[cont++] = pair<double, double>(aux, auy);
         }
      }

      for(int i = 1; i < n; ++i){
         cin >> aua >> aub;
         adj[cities[aua]].push_back(cities[aub]);
         adj[cities[aub]].push_back(cities[aua]);
      }

      dfs(1);

      cout << solve(1) << endl;
   }


   return 0;
}
