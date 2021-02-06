#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int player[510];
int main(){
   ios_base::sync_with_stdio(0);
   int n, r, aux, ans, best;
   cin >> n >> r;
   for(int i = 0; i != r; ++i)
      for(int j = 1; j <= n; ++j){
         cin >> aux;
         player[j] += aux;
      }
   best = player[1];
   for(int i = 1; i <= n; ++i)
      if(player[i] >= best){
         best = player[i];
         ans = i;
      }
   cout << ans << "\n";

   return 0;
}
