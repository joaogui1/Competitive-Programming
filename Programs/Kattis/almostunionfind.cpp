#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll sum[200200];
int pai[200200], rak[200200];

int find(int i){
  return (i == pai[i]) ? i:pai[i] = find(pai[i]);
}

void join(int x, int y){
  x = find(x), y = find(y);
  if(x == y)  return;
  if(rak[x] > rak[y]){
    sum[x] += sum[y];
    rak[x] += rak[y];
    pai[y] = x;
  }
  else{
    sum[y] += sum[x];
    rak[y] += rak[x];
    pai[x] = y;
  }
  return;
}

void move(int x, int y){
  y = find(y);
  ++rak[y];
  sum[y] += x;
  --rak[find(x)];
  sum[find(x)] -= x;
  pai[x] = find(y);
  return;
}

void initialize(){
  for(int i = 100001; i <= 200000; ++i) pai[i] = i, rak[i] = 1, sum[i] = i - 100000;
  for(int i = 1; i <= 100000; ++i) pai[i] = i + 100000, rak[i] = 1;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, m, op, p, q;
  while(cin >> n >> m){
    initialize();
    while(m--){
      cin >> op >> p;
      if(op == 1){
        cin >> q;
        join(p, q);
      }
      if(op == 2){
        cin >> q;
        move(p, q);
      }
      if(op == 3) cout << rak[find(p)] << " " << sum[find(p)] << "\n";
    }
  }


  return 0;
}
