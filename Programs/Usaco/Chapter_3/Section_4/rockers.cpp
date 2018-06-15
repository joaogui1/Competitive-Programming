/*
ID: joaogui1
LANG: C++
TASK: rockers
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
int musics[25], dp[(1 << 20) + 10][3];
int main(){
   ios_base::sync_with_stdio(0);
   int n, t, m, ans = 0, cont = 0, test, msb;
   ifstream fin ("rockers.in");
   ofstream fout ("rockers.out");
   fin >> n >> t >> m;
   for(int i = 0; i < n; ++i) fin >> musics[i];
   dp[0][1] = 1;
   for(int mask = 1; mask < 1 << n; ++mask){
      int disks[25] = {0};
      cont = 1, test = msb = 0;
      for(int i = n; i > -1; --i)
         if((1 << i) <= mask){
            msb = i;
            break;
         }
      test = dp[mask - (1 << msb)][0];
      cont = dp[mask - (1 << msb)][1];
      disks[cont] = dp[mask - (1 << msb)][2];
      if(cont <= m){
         if(disks[cont] + musics[msb] <= t) disks[cont] += musics[msb];
         else if(++cont <= m && musics[msb] <= t)  disks[cont] += musics[msb];
         else{
            cont = m;
            --test;
         }
         ++test;
      }
      dp[mask][0] = test;
      dp[mask][1] = cont;
      dp[mask][2] = disks[cont];
      ans = max(test, ans);
      //cout << ans << " " << mask << endl;
      //cout << (1 << n) << endl;
   }

   //for(int i = 1; i <= n; ++i)
      //cout << dp[(1 << i) - 1][0] << " " << dp[(1 << i) - 1][1] << " " << dp[(1 << i) - 1][2] << endl;



   fout << ans << "\n";

   return 0;
}
