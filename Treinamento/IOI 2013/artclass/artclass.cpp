#include "artclass.h"
#include <bits/stdc++.h>

using namespace std;

double dist(int a, int b, int c, int x, int y, int z){
  double d = abs(a - x) + abs(b - y) + abs(c - z);
  return d;
}

double mean(int R[500][500], int G[500][500], int B[500][500], int x, int y){
  double ret = 0;
  int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
  for(int i = 0; i < 4; ++i)
    ret += dist(R[x][y], G[x][y], B[x][y], R[x + dx[i]][y + dy[i]], G[x + dx[i]][y + dy[i]], B[x + dx[i]][y + dy[i]]);
  return ret;
}

int style(int H, int W, int R[500][500], int G[500][500], int B[500][500]) {
    double d = 0;
    for(int i = 1; i < H - 1; ++i)
      for(int j = 1; j < W - 1; ++j){
        d += mean(R, G, B, i, j);
      }
    d /= H*W;
    //cout << d << "\n";
    // cout << d << " ";
    if(d < 40)  return 4;
    if(105 >= d) return 1;
    if(220 > d)  return 2;
    else return 3;
    //return d;
}
