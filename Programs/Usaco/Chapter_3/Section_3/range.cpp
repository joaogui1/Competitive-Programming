/*
ID: joaogui1
LANG: C++
TASK: range
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
int G[260][260], mark[260][260], ans[260];

int quad(int a, int b, int c, int d){
   return G[a][b] - G[c - 1][b] - G[a][d - 1] + G[c - 1][d - 1];
}

int main(){
   ios_base::sync_with_stdio(0);
   int n;
   bool vdc;
   string input[260];
   ifstream fin ("range.in");
   ofstream fout ("range.out");
   fin >> n;
   for(int i = 1; i <= n; ++i) fin >> input[i];
   for(int i = 1; i <= n; ++i)
      for(int j = 0; j < n; ++j)
         G[i][j + 1] = input[i][j] - '0';

   for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j){
         if(i > 1)   G[i][j] += G[i - 1][j];
         if(j > 1)   G[i][j] += G[i][j - 1];
         if(i > 1 && j > 1)   G[i][j] -= G[i - 1][j - 1];
      }

   for(int i = 2; i <= n; ++i)
      for(int j = 2; j <= n; ++j){
         for(int test = 1; min(i, j) - test > 0; ++test){
            //fout << G[i][j] << " " << G[i - test - 1][j] << " " << G[i][j - test - 1] << " " << G[i - test - 1][j - test - 1] << endl;
            if(quad(i, j, i - test, j - test) == (test + 1)*(test + 1)){
               //fout << G[i][j] << " " << G[i - test - 1][j] << " " << G[i][j - test - 1] << " " << G[i - test - 1][j - test - 1] << endl;
               ++ans[test + 1];
             }
            else  break;
         }
      }

   for(int i = 2; i <= 250; ++i) if(ans[i])  fout << i << " " << ans[i] << "\n";

   return 0;
}
