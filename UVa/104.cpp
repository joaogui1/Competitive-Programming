#include <bits/stdc++.h>

using namespace std;

int cycle[32];
int path[32][32][32];
double G[32][32][32], aux;

void fw(int n){
  for(int l = 1; l < n; ++l){
    for(int k = 0; k < n; ++k){
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
          double aux = G[i][k][l-1] * G[k][j][0];
          if(aux > G[i][j][l]){
            G[i][j][l] = aux;
            path[i][j][l] = k;
          }
        }
      }
    }
  }

  return;
}

void initialize(){
  memset(path, -1, sizeof path);
  memset(cycle, 0, sizeof cycle);
  for(int i = 0; i < 32; ++i)
    for(int j = 0; j < 32; ++j)
      for(int k = 0; k < 32; ++k)
        G[i][j][k] = 0.0;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  bool vdc;
  while(cin >> n){
    vdc = 0;
    initialize();
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j){
        path[i][j][0] = i;
        if(i == j)  G[i][j][0] = 1.000;
        else  cin >> G[i][j][0];
      }
    fw(n);

    for(int l = 1; l < n && !(vdc); ++l){
      for(int i = 0; i < n; ++i){
        if(G[i][i][l] > 1.01){
          cycle[l] = path[i][i][l];
          for(int j = l - 1; j >= 0; --j)
            cycle[j] = path[i][cycle[j + 1]][j];
          for(int j = 0; j < l + 1; ++j)
            cout << cycle[j] + 1 << " ";
          cout << cycle[0] + 1 << "\n";
          vdc = 1;
          break;

        }
      }
    }
    if(!vdc)  cout << "no arbitrage sequence exists\n";

  }



  return 0;
}
