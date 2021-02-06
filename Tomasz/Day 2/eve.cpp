#include <bits/stdc++.h>

using namespace std;
int v[100100];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, sum = 0, zl = 0, zr = 0, f1 = (1 << 20), l1 = 0, r1 = 0;
  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> v[i], v[i] %= 2, sum += v[i];
  for(int i = 1; i <= n; ++i){
    if(v[i] == 0) continue;
    f1 = min(f1, i);
    r1 = l1;
    l1 = i;
  }
  if(r1 == 0) r1 = f1;
  if(f1 == (1 << 20)) f1 = 0;
  for(int i = 1; i < f1; ++i)
    zl += (v[i] == 0);

  for(int i = max(r1, f1) + 1; i < l1; ++i)
    zl += (v[i] == 0);

  for(int i = l1 + 1; i <= n; ++i)
    zr += (v[i] == 0);

  if((sum%2) == 0){
    cout << 1 << " " << n << "\n";
  }

  else if(v[n] == 1 && n != 1){
    cout << 1 << " " << n - 1 << "\n";

  }
  else if(v[n] == 1 && n == 1){
    cout << "NIE\n";
  }
  else if(sum == 1 && v[1] == 1){
    cout << 2 << " " << n << "\n";
  }

  else if(zl == zr && sum != 1){
    cout << f1 << " " << r1 << "\n";
  }

  else if(zl == zr && sum == 1){
    cout << "NIE\n";
  }

  else if(zl > zr){
    int cont = 0, ini = 1, fim = 1;
    if(f1 == l1){
      for(fim = 1; cont < zl - zr && fim < l1; ++fim)
        cont += (v[fim] == 0);
      --fim;
    }
    else{
      for(ini = f1; cont < zl - zr && ini > 0; --ini)
        cont += (v[ini] == 0);
      ++ini;
      for(fim = r1; cont < zl - zr && fim < l1; ++fim)
        cont += (v[fim] == 0);
      if(fim != r1) --fim;
    }
    if(fim == l1) --fim;
    cout << ini << " " << fim << "\n";
  }
  else if(zl < zr){
    int fim;
    zl = zr = 0;
    for(int i = 1; i < f1; ++i) zl += (v[i] == 0);
    for(fim = n; fim > f1 && zr < zl; --fim)
      zr += (v[fim] == 0);
    fim = max(fim, l1);
    cout << f1 + 1 << " " << fim << "\n";
  }
  return 0;
}
