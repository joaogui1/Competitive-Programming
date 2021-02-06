#include <bits/stdc++.h>

using namespace std;

int pai[100010], rak[100010];

int find(int x){
  return ((pai[x] == x)?x:(pai[x] = find(pai[x])));
}

void join(int x, int y){
  x = find(x);y = find(y);
  if(rak[x] > rak[y])
    pai[y] = x;

  else if(rak[y] > rak[x])
    pai[x] = y;

  else{
    pai[y] = x;
    ++rak[x];
  }
  return;
}

void initialize(){
  memset(rak, 0, sizeof rak);
  for(int i = 0; i <= 100010; ++i) pai[i] = i;

}

int main(){
  ios_base::sync_with_stdio(0);
  int n, k, aux, auy;
  cin >> n >> k;
  initialize();
  while(k--){
    cin >> aux >> auy;
    if(find(aux) != find(auy)){
      join(aux, auy);
      --n;
    }
  }
  cout << n << "\n";


  return 0;
}
