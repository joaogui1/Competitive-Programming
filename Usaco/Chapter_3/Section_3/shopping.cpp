/*
ID: joaogui1
LANG: C++
TASK: shopping
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[9][9][9][9][9], cont, need[9], price[9], c[9], offer[110][1100];

int main(){
   ios_base::sync_with_stdio(0);
   int s, n, aux, b;
   ifstream fin ("shopping.in");
   ofstream fout ("shopping.out");
   fin >> s;
   for(int i = 1; i <= s; ++i){
      fin >> n;
      for(int j = 1; j <= n; ++j){
            fin >> aux;
            fin >> offer[i][aux];
      }
      fin >> offer[i][1050];
   }

   fin >> b;
   for(int i = 1; i <= b; ++i)   fin >> c[i] >> need[i] >> price[i];

   for(int i1 = 0; i1 <= need[1]; ++i1)
   for(int i2 = 0; i2 <= need[2]; ++i2)
   for(int i3 = 0; i3 <= need[3]; ++i3)
   for(int i4 = 0; i4 <= need[4]; ++i4)
   for(int i5 = 0; i5 <= need[5]; ++i5)
   dp[i1][i2][i3][i4][i5] = i1*price[1] + i2*price[2] + i3*price[3] + i4*price[4] + i5*price[5];

   for(int i1 = 0; i1 <= need[1]; ++i1)
   for(int i2 = 0; i2 <= need[2]; ++i2)
   for(int i3 = 0; i3 <= need[3]; ++i3)
   for(int i4 = 0; i4 <= need[4]; ++i4)
   for(int i5 = 0; i5 <= need[5]; ++i5)
   for(int i = 1; i <= s; ++i){
      //fout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << i5 << endl;
      //fout << offer[i][c[1]] << " " <<  offer[i][c[2]] << " " <<  offer[i][c[3]] << " " <<  offer[i][c[4]] << " " <<  offer[i][c[5]] << endl;
      if(i1 >= offer[i][c[1]] &&  i2 >= offer[i][c[2]] && i3 >= offer[i][c[3]] && i4 >= offer[i][c[4]] && i5 >= offer[i][c[5]]){
         //fout << "Ok\n";
         //fout << i1-offer[i][c[1]] << " " << i2 - offer[i][c[2]] << " "  << i3 - offer[i][c[3]] << " " << i4 << " " << i5 << "    ";
         //fout << dp[i1][i2][i3][i4][i5] << "    ";
         //fout << dp[i1-offer[i][c[1]]][i2 - offer[i][c[2]]][i3 - offer[i][c[3]]][i4 - offer[i][c[4]]][i5 - offer[i][c[5]]];
         //fout << "   " << offer[i][1050] << endl;
         dp[i1][i2][i3][i4][i5] = min(dp[i1][i2][i3][i4][i5], dp[i1-offer[i][c[1]]][i2 - offer[i][c[2]]][i3 - offer[i][c[3]]][i4 - offer[i][c[4]]][i5 - offer[i][c[5]]] + offer[i][1050]);
      }
      //fout << dp[need[1]][need[2]][need[3]][need[4]][need[5]]<< "\n";
   }
   /*fout << endl << endl;
   for(int i1 = 0; i1 <= need[1]; ++i1)
   for(int i2 = 0; i2 <= need[2]; ++i2)
   for(int i3 = 0; i3 <= need[3]; ++i3)
   for(int i4 = 0; i4 <= need[4]; ++i4)
   for(int i5 = 0; i5 <= need[5]; ++i5)
   fout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << i5 << " " << dp[i1][i2][i3][i4][i5] << "\n";

   fout << endl << endl;*/
   fout << dp[need[1]][need[2]][need[3]][need[4]][need[5]]<< "\n";

   return 0;
}
