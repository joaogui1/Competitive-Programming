#include <bits/stdc++.h>
#define MOD 10007

using namespace std;

int dp[100020][2], mark[100020];
long long int dpf[100020][2];
vector <int> adj[100020], child[100020];

int cover(int x, int add){
   if(dp[x][add] != 0)  return dp[x][add];
   if(child[x].size() == 0)   return add;

   int ret = add;
   if(!add)
      for(int i = 0; i < child[x].size(); ++i)
         ret += cover(child[x][i], 1);

   else
      for(int i = 0; i < child[x].size(); ++i)
         ret += min(cover(child[x][i], 1), cover(child[x][i], 0));
   return dp[x][add] = ret;

}

void dfs(int x){
   int v;
   ++mark[x];
   for(int i = 0; i < adj[x].size(); ++i){
      v = adj[x][i];
      if(!mark[v]){
         child[x].push_back(v);
         dfs(v);
      }
   }
   return;
}

long long int f(int x, int add){
   if(child[x].size() == 0)   return 1;
   if(dpf[x][add] != 0) return dpf[x][add];

   int v;
   long long int ret = 1;
   if(add == 0)
      for(int i = 0; i < child[x].size(); ++i){
         ret *= f(child[x][i], 1);
         ret %= MOD;
      }
   else
      for(int i = 0; i < child[x].size(); ++i){
         v = child[x][i];
         if(cover(v, 1) < cover(v, 0))
            ret *= f(v, 1);
         else if(cover(v, 0) < cover(v, 1))
            ret *= f(v, 0);
         else
            ret *= (f(v, 0)+f(v, 1))%MOD;
         ret %= MOD;
      }

   return dpf[x][add] = ret;
}

int main(){
   int t, n, a, b;
   cin >> t;
   while(t--){
      cin >> n;
      for(int i = 0; i < 100020; ++i) adj[i].clear();
      for(int i = 0; i < 100020; ++i) child[i].clear();
      memset(dp, 0, sizeof dp);
      memset(dpf, 0, sizeof dpf);
      memset(mark, 0, sizeof mark);
      for(int i = 1; i < n; ++i){
         cin >> a >> b;
         adj[a].push_back(b);
         adj[b].push_back(a);
      }

      dfs(1);
      cout << min(cover(1, 0), cover(1, 1)) << " ";
      if(dp[1][0] < dp[1][1])
         cout << (f(1, 0)%MOD) << "\n";
      else if(dp[1][1] < dp[1][0])
         cout << (f(1, 1)%MOD) << "\n";
      else
         cout << ((f(1, 0)+f(1, 1))%MOD) << "\n";
   }



   return 0;
}
