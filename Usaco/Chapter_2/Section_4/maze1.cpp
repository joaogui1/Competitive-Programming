/*
ID: joaogui1
LANG: C++
TASK: maze1
*/
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
#define ok "ok"
#define debug(a, b, c, d ,e)  std::cout << a << " " << b << " " << c << " " << d << " " << e << endl
using namespace std;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, dist[3][80][110], grid[80][110], mark[80][110];
queue <pair <char, char> > q;
int main(){
   int w, h, cont = 1, mx = 0, ans;
   string input;
   pair <int, int> exi[5], aux;
   ifstream fin ("maze1.in");
   ofstream fout ("maze1.out");
   fin >> w >> h;
   getline(fin, input);
   for(int i = 0; i < 2*h + 1; ++i){
      getline(fin, input);
      if(i%2 == 0)
         for(int j = 0; j < 2*w + 1; ++j){
            if(input[j] == '-'){
               grid[(j-1)/2][i/2] += 4;
               if(i != 0)  grid[(j-1)/2][i/2 - 1] += 1;
            }
         }
      else{
         for(int j = 0; j < 2*w + 1; ++j)
            if(input[j] == '|'){
               grid[j/2][(i-1)/2] += 8;
               if(j != 0)  grid[j/2 - 1][(i-1)/2] += 2;
            }
      }
      if(input[2*w] == ' ') exi[cont++] = make_pair(w-1, (i-1)/2);
      if(input[0] == ' ') exi[cont++] = make_pair(0, (i-1)/2);
   }
   for(int i = 0; i < w; ++i) if(!(grid[i][0] & 4)) exi[cont++] = make_pair(i, 0);
   for(int i = 0; i < w; ++i) if(!(grid[i][h-1] & 1)) exi[cont++] = make_pair(i, h-1);
   cont = 0;
   for(int j = 1; j < 3; ++j){
      q.push(exi[j]);
      memset(mark, 0, sizeof(mark));
      while(!q.empty()){
         aux = q.front();q.pop();
         for(int i = 0; i < 4; ++i){
            if(!(grid[aux.first][aux.second] & 1 << i) && aux.first + dx[i] > -1 && aux.first + dx[i] < w && aux.second + dy[i] > -1 && aux.second + dy[i] < h){
               if(mark[aux.first + dx[i]][aux.second + dy[i]] == 0){
                  q.push(make_pair(aux.first + dx[i], aux.second + dy[i]));
                  ++mark[aux.first  + dx[i]][aux.second + dy[i]];
                  dist[j][aux.first + dx[i]][aux.second + dy[i]] = dist[j][aux.first][aux.second] + 1;
               }
            }
         }
      }
   }

   for(int i = 0; i < h; ++i)
      for(int j = 0; j < w; ++j)
         dist[0][j][i] = min(dist[1][j][i], dist[2][j][i]);
   for(int i = 0; i < h; ++i)
      for(int j = 0; j < w; ++j)
         if(mx < dist[0][j][i])  mx = dist[0][j][i];
   fout << mx + 1 << endl; //a dist inicial deve ser 1 e nao zero
   return 0;
}
