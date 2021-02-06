#include <bits/stdc++.h>

using namespace std;

int cont, pai[200200], rak[200200];
map<string, int> dict;

int find(int x){
  return (x == pai[x])? x : pai[x] = find(pai[x]);
}

void join(int x, int y){
  x = find(x), y = find(y);
  if(x == y){
    cout << rak[x] << "\n";
    return;
  }
  if(rak[x] > rak[y]){
    rak[x] += rak[y];
    pai[y] = x;
    cout << rak[x] << "\n";
  }
  else{
    rak[y] += rak[x];
    pai[x] = y;
    cout << rak[y] << "\n";
  }
  return;
}

void initialize(){
  cont = 0;
  for(int i = 0; i < 200200; ++i) pai[i] = i, rak[i] = 1;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, t;
  string aus, aur;
  cin >> t;
  while(t--){
    initialize();
    cin >> n;

    for(int i = 0; i < n; ++i){
      cin >> aus >> aur;
      if(dict.count(aus) == 0)  dict[aus] = cont++;
      if(dict.count(aur) == 0)  dict[aur] = cont++;
      join(dict[aus], dict[aur]);
    }
  }


  return 0;
}
