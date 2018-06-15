/*
ID: joaogui1
LANG: C++
TASK: ttwo
*/
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
#define N 0
#define D 1
#define S 2
#define E 3
using namespace std;
char grid[15][15];
bool mark[15][15][15][15][8][8];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main(){
   int xc, yc, dc, xf, yf, df, cont = 0;
   ifstream fin ("ttwo.in");
   ofstream fout ("ttwo.out");
   for(int i = 10; i >= 1; --i)
      for(int j = 1; j <= 10; ++j){
         fin >> grid[j][i];
         if(grid[j][i] == 'C'){
            xc = j;
            yc = i;
            dc = N;
         }
         if(grid[j][i] == 'F'){
            xf = j;
            yf = i;
            df = N;
         }
      }
   while(xf != xc || yf != yc){
      if(mark[xc][yc][xf][yf][dc][df]++){
         fout << 0 << endl;
         break;
      }
      if(grid[xc + dx[dc]][yc + dy[dc]] == '*' || xc + dx[dc] > 10 || yc + dy[dc] > 10 || yc + dy[dc] < 1 || xc + dx[dc] < 1 ){
         dc += 1;dc%=4;
      }
      else{
         xc += dx[dc];
         yc += dy[dc];
      }
      if(grid[xf + dx[df]][yf + dy[df]] == '*' || xf + dx[df] > 10 || yf + dy[df] > 10 || yf + dy[df] < 1 || xf + dx[df] < 1){
         df += 1;df%=4;
      }
      else{
         xf += dx[df];
         yf += dy[df];
      }
      ++cont;
   }

   if(xf == xc && yf == yc)   fout << cont << endl;



   return 0;
}
