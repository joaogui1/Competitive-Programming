#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
int G[110][110];
bool check(int i, int j, int n){
   for(int var_i = 0; var_i < n; ++var_i)
      for(int var_j = 0; var_j < n; ++var_j){
         if(var_i == var_j && G[j + var_j][i + var_i] != 1) return 0;
         else if(var_i != var_j && G[j + var_j][i + var_i] != 0)  return 0;
      }
   return 1;
}
int main(){
   ios_base::sync_with_stdio(0);
   int t, n, ans;
   cin >> t;
   while(t--){
      ans = 0;
      cin >> n;
      for(int i = 1; i <= n; ++i)
         for(int j = 1; j <= n; ++j)
            cin >> G[j][i];
      for(int i = 1; i <= n; ++i)
         for(int j = 1; j <= n; ++j){
            if(G[j][i] == 1){
               ++ans;
               for(int k = 2; k + max(i, j) - 1 <= n; ++k){
                  if(check(i, j, k))   ++ans;
                  else  break;
               }
            }
         }
      cout << ans << "\n";
   }

   return 0;
}
