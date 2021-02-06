#include <bits/stdc++.h>

using namespace std;

int pai[100010], rak[100010];
multiset<int> sizes;

int find(int x){
  return ((pai[x] == x)?x:(pai[x] = find(pai[x])));
}

void join(int x, int y){
  x = find(x), y = find(y);

  if(x != y){
    auto auy = sizes.find(rak[x]);
    if(auy != sizes.end())  sizes.erase(auy);
    auy = sizes.find(rak[y]);
    if(auy != sizes.end())  sizes.erase(auy);

    sizes.insert(rak[x] + rak[y]);
    if(rak[x] > rak[y]){
      pai[y] = x;
      rak[x] += rak[y];
    }
    else{
      pai[x] = y;
      rak[y] += rak[x];
    }
  }
  auto aux = sizes.end();
  --aux;
  cout << *(aux) - *(sizes.begin()) << "\n";

  return;
}

void initialize(int n){
  sizes.clear();
  for(int i = 0; i <= n; ++i) rak[i] = 1;
  for(int i = 0; i < n; ++i)  sizes.insert(1);
  for(int i = 0; i < 100010; ++i) pai[i] = i;
}

int main(){
  int n, q, a, b;
  cin >> n >> q;
  initialize(n);
  while(q--){
    cin >> a >> b;
    join(a, b);
    //for(int const & i : sizes)  cout << i << " ";
    //cout << endl;
  }

  return 0;
}
