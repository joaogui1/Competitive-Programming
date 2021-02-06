#include <bits/stdc++.h>

using namespace std;

int n, c, t1, t2, dp[2020][1010], ant[2][2020];
vector <int> pos;

int cover(int x, int cut){
   int ret[2];

   if(dp[x][cut] > 0)  return dp[x][cut];

   if(pos[x] - pos[cut] <= t1)  ret[0] = t1;
   else {
	  ret[0] = t1 + cover(ant[0][x], cut);
   }




   if(pos[x] - pos[cut] <= t2)  ret[1] = t2;
   else{
	  ret[1] = t2 + cover(ant[1][x], cut);
   }

   return dp[x][cut] = min(ret[0], ret[1]);
}

int main(){
   ios_base::sync_with_stdio(0);
   int ans = (1 << 30), aux;

   while(cin >> n >> c >> t1 >> t2){
      memset(dp, 0, sizeof dp);
      ans = (1 << 30);
      pos.clear();

      for(int i = 0; i < n; ++i){
            cin >> aux;
            pos.push_back(aux);
      }
      for(int i = 0; i < n; ++i)   pos.push_back(pos[i] + c);

      for(int i = 0; i < 2; ++i)
         for(int j = 0; j < 2*n; ++j) ant[i][j] = -1;


      for(int i = 0; i < 2*n; ++i){
         for(int j = 0; j < i; ++j)
            if(pos[i] - pos[j] > t1)
               ant[0][i] = j;


         for(int j = 0; j < i; ++j)
            if(pos[i] - pos[j] > t2)
               ant[1][i] = j;

      }

      for(int i = 0; i < n; ++i){

         ans = min(ans, cover(i + n - 1, i));
      }

      cout << ((n == 1)?min(t1, t2):ans) << "\n";
   }




   return 0;
}
