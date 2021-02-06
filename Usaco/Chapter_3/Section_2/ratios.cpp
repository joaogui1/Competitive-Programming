/*
ID: joaogui1
LANG: C++
TASK: ratios
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int goal_rat[6], rat[6][6], sum = 400, ans;
int main(){
   ios_base::sync_with_stdio(0);
   ifstream fin ("ratios.in");
   ofstream fout ("ratios.out");
   fin >> goal_rat[1] >> goal_rat[2] >> goal_rat[3];
   for(int i = 1; i <= 3; ++i)
      fin >> rat[i][1] >> rat[i][2] >> rat[i][3];
   for(int i = 0; i <= 100; ++i)
      for(int j = 0; j <= 100; ++j)
         for(int k = 0; k <= 100; ++k){
            //cout << i + j + k << " " << sum << endl;
            if(i + j + k < sum && (i != 0 || j != 0 || k != 0)){
               for(int q = 1; q <= 3; ++q)rat[4][q] = i*rat[1][q] + j*rat[2][q] + k*rat[3][q];
               if(rat[4][1]*goal_rat[2] == rat[4][2]*goal_rat[1] && rat[4][2]*goal_rat[3] == rat[4][3]*goal_rat[2])
                  if(rat[4][1] >= goal_rat[1] && rat[4][2] >= goal_rat[2] && rat[4][3] >= goal_rat[3]){
                     ans = rat[4][2]/goal_rat[2];
                     sum = i + j + k;
                     rat[5][1] = i;
                     rat[5][2] = j;
                     rat[5][3] = k;
               }
            }
         }
   if(rat[5][1] != 0 || rat[5][2] != 0 || rat[5][3] != 0){
      fout << rat[5][1] << " " << rat[5][2] << " " << rat[5][3] << " " << ans;
   }
   else  fout << "NONE";
   fout << "\n";
   return 0;
}
