#include <bits/stdc++.h>
#define INF 1 << 10

using namespace std;

int G[32][32];

void fw(){
  for(int k = 0; k < 20; ++k)
    for(int i = 0; i < 20; ++i)
      for(int j = 0; j < 20; ++j)
        G[i][j] = min(G[i][k] + G[k][j], G[i][j]);
  return;
}

void initialize(){
  for(int i = 0; i < 32; ++i)
    for(int j = 0; j < 32; ++j)
      G[i][j] = INF;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, aux, auy, cont = 0;
  while(1){
    initialize();
    for(int i = 0; i < 19; ++i){
      cin >> n;
      if(cin.eof()) return 0;
      for(int j = 0; j < n; ++j){
        cin >> aux;
        G[i][aux - 1] = G[aux - 1][i] = 1;
      }
    }
    cin >> n;
    fw();
    cout << "Test Set #" << ++cont << "\n";
    //cout << "ok " << n << endl;
    for(int i = 0; i < n; ++i){
      cin >> aux >> auy;
      cout << setw(2) << aux << " to " << setw(2) << auy << ":" << setw(2) << G[aux - 1][auy - 1] << "\n";
    }
    cout << "\n";
  }



  return 0;
}
