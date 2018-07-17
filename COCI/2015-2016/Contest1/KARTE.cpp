#include <bits/stdc++.h>

using namespace std;

int f[8][16];
string s;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s;
  int aux;
  char a, b, c;
  for(int i = 0; i < s.size(); i += 3){
    a = s[i];
    b = s[i + 1];
    c = s[i + 2];
    aux = 10*(b - '0') + (c - '0');
    if(a == 'P'){
      if(f[0][aux]){
        cout << "GRESKA\n";
        return 0;
      }
      f[0][aux] = 1;
    }
    else if(a == 'K'){
      if(f[1][aux]){
        cout << "GRESKA\n";
        return 0;
      }
      f[1][aux] = 1;
    }
    else if(a == 'H'){
      if(f[2][aux]){
        cout << "GRESKA\n";
        return 0;
      }
      f[2][aux] = 1;
    }
    else{
      if(f[3][aux]){
        cout << "GRESKA\n";
        return 0;
      }
      f[3][aux] = 1;
    }
  }
  for(int i = 0; i < 4; ++i){
    aux = 0;
    for(int j = 1; j < 14; ++j) aux += (1 - f[i][j]);
    cout << aux << " \n"[i == 3];
  }

  return 0;
}
