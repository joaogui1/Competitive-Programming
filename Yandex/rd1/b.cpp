#include <bits/stdc++.h>

using namespace std;

int g[3][3];
string s[3];

void pre(){
  g[1][1] = 1;
  g[0][1] = 2;
  g[0][2] = 3;
  g[1][2] = 4;
  g[2][2] = 5;
  g[2][1] = 6;
  g[2][0] = 7;
  g[1][0] = 8;
  g[0][0] = 9;
}

void rt(){
  int aux;
  aux = g[0][2];
  g[0][2] = g[0][1];
  g[0][1] = g[0][0];
  g[0][0] = g[1][0];
  g[1][0] = g[2][0];
  g[2][0] = g[2][1];
  g[2][1] = g[2][2];
  g[2][2] = g[1][2];
  g[1][2] = aux;
}

void rf(){
  for(int i = 0; i < 3; ++i)  swap(g[i][0], g[i][2]);
  return;
}

int main(){
  pre();
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  bool vdc;
  for(int i = 0; i < 3; ++i)  cin >> s[i];
  for(int i = 0; i < 8; ++i){
    rt();
    vdc = 1;
    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j)
        vdc &= (s[i][j] == '?' || g[i][j] == (s[i][j] - '0'));
    if(vdc){
      for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j)
          cout << g[i][j];
        cout << "\n";
      }
      return 0;
    }
  }
  rf();
  for(int i = 0; i < 8; ++i){
    rt();
    vdc = 1;
    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j)
        vdc &= (s[i][j] == '?' || g[i][j] == (s[i][j] - '0'));
    if(vdc){
      for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j)
          cout << g[i][j];
        cout << "\n";
      }
      return 0;
    }
  }
  return 0;
}
