/*
ID: joaogui1
LANG: C++
TASK: spin
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
int v[7], w[7], b[7][7], e[7][7], at[7][7];
int main(){
   ios_base::sync_with_stdio(0);
   int t, sai = 0;
   ifstream fin ("spin.in");
   ofstream fout ("spin.out");
   for(int i = 1; i <= 5; ++i){
      fin >> v[i] >> w[i];
      for(int j = 1; j <= w[i]; ++j)   fin >> b[i][j] >> e[i][j];
   }
   for(t = 0; t <= 360; ++t){
      int op[370] = {0};
      for(int i = 1; i <= 5; ++i)
         for(int j = 1; j <= w[i]; ++j)
            at[i][j] = (b[i][j] + v[i]*t)%360;
      for(int i = 1; i <= 5; ++i)
         for(int j = 1; j <= w[i]; ++j)
            for(int k = 0; k <= e[i][j]; ++k)
               if(++op[(at[i][j] + k)%360] == 5)   sai = 1;
      //for(int i = 0; i < 360; ++i)  cout << op[i] << " ";
      //cout << "\n" << "\n" << "\n";
      if(sai)  break;
   }
   if(sai)  fout << t << "\n";
   else  fout << "none" << "\n";
   return 0;
}
