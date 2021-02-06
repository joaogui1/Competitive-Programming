/*
ID: joaogui1
LANG: C++
TASK: castle
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
int sizes[2510], rooms[60][60], dx[4] = {-1, 0 , 1, 0}, dy[4] = {0, -1, 0, +1}, mark[60][60], id_max_y, id_max_x,  id_max_char, n, m;
vector <pair < pair <int, int>, int> > id_max;
char car[4] ={'W', 'N',  'E', 'S'};
bool comp(pair < pair <int, int>, int> a, pair <pair <int, int>, int> b){
   if(a.first.first < b.first.first) return 1;
   if(a.first.first > b.first.first) return 0;
   if(a.first.second > b.first.second) return 1;
   if(a.first.second < b.first.second) return 0;
   if(a.second < b.second) return 1;
   return 0;
}
void dfs(int x, int y, int id){
   if(x <= 0 || y <= 0 || m  < x || n < y) return;
   mark[x][y] = id;
   ++sizes[id];
   for(int i = 0; i < 4; ++i)
      if(!mark[x + dx[i]][y + dy[i]] && !(rooms[x][y] & 1 << i))   dfs(x + dx[i], y + dy[i], id);
   return;
}
int find_sizes(int m, int n){
   int ret = 0, aux;
   for(int i = 1; i <= m; ++i)
      for(int j = n; j > 0 ; --j){
         aux = sizes[mark[i][j]];
         for(int k = 0; k < 4; ++k)
            if(rooms[i][j] & 1 << k){
               if(mark[i + dx[k]][j + dy[k]] && mark[i][j] != mark[i + dx[k]][j + dy[k]] && aux + sizes[mark[i + dx[k]][j + dy[k]]] > ret){
                  ret = aux + sizes[mark[i + dx[k]][j + dy[k]]];
                  id_max_x = i;
                  id_max_y = j;
                  id_max_char = k;
               }
            }
      }
   return ret;
}
int main(){
   int  id = 0, aux = 0;
   ifstream fin ("castle.in");
   ofstream fout ("castle.out");
   fin >> m >> n;
   for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= m; ++j)
         fin >> rooms[j][i];
   for(int a = 1; a <= n; ++a)
      for(int b = 1; b <= m; ++b)
         if(!mark[b][a])   dfs(b, a, ++id);
   fout << id << endl;
   for(int i = 1; i <= id; ++i)
      if(sizes[i] > aux)   aux = sizes[i];
   fout << aux << endl;
   fout << find_sizes(m, n) << endl;
   sort(id_max.begin(), id_max.end(), comp);
   fout << id_max_y << " " << id_max_x << " " << car[id_max_char] << endl;

   return 0;
}
