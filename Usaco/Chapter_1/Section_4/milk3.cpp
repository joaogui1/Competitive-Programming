/*
ID: joaogui1
LANG: C++
TASK: milk3
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
int states[30][30][30], a, b, c;
vector <int> ans;
void dfs(int x, int y, int z){
   states[x][y][z] = 1;
   if(a >= z+x && !states[z + x][y][0])   dfs( z + x, y, 0);
   if(a < z+x && !states[a][y][z + x - a])   dfs(a, y, z + x - a);
   if(b >= z+y && !states[x][z + y][0])   dfs( x, z + y, 0);
   if(b < z+y && !states[x][b][z + y - b])   dfs(x, b, z + y - b);
   if(a >= y+x && !states[y + x][0][z])   dfs( y + x, 0, z);
   if(a < y+x && !states[a][x + y - a][z])   dfs(a, x + y - a, z);
   if(c >= z+y && !states[x][0][z + y])   dfs( x, 0, z + y);
   if(c < z+y && !states[x][y + z - c][c])   dfs(x, y + z - c, c);
   if(b >= x+y && !states[0][x + y][z])   dfs( 0, x + y, z);
   if(b < x+y && !states[x + y - b][b][z])   dfs(x + y - b, b, z);
   if(c >= z + x && !states[0][y][z + x])   dfs( 0, y, z + x);
   if(c < z + x && !states[x + z - c][y][c])   dfs(x + z - c, y, c);
   return;
}
int main(){
   ifstream fin ("milk3.in");
   ofstream fout ("milk3.out");
   fin >> a >> b >> c;
   dfs(0, 0, c);
   for(int i = 0; i <= b; ++i)
      for(int j = 0; j <= c; ++j)
         if(states[0][i][j])  ans.push_back(j);
   sort(ans.begin(), ans.end());
   int sz = ans.size();
   for(int i = 0; i < sz-1; ++i)
      fout << ans[i] << " ";
   fout << ans[sz-1] << endl;



   return 0;
}
