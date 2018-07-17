#include <bits/stdc++.h>

using namespace std;

int BIT[30][100100];

void update(int *ft, int x, int v){
    for(; x <= 100100; x += x&(-x))
      ft[x] += v;
    return;
}

int query(int *ft, int x){
  int sum = 0;
  for(; x > 0; x -= x&(-x))
    sum += ft[x];
  return sum;
}

int query(int* ft, int a, int b){
  return query(ft, b) - query(ft, a - 1);
}

int main(){
  int n, q, op, aux1, aux2, ans = 0;
  char aux_c;
  string input;
  cin >> n >> q;
  cin >> input;
  for(int i = 0; i < input.size(); ++i)
    update(BIT[input[i] - 'a'], i + 1, 1);
  for(int i = 0; i < q; ++i){
    cin >> op;
    if(op == 1){
      cin >> aux1 >> aux_c;
      update(BIT[input[aux1 - 1] - 'a'], aux1, -1);
      update(BIT[aux_c - 'a'], aux1, 1);
      input[aux1 - 1] = aux_c;
    }

    else{
      ans = 0;
      cin >> aux1 >> aux2;
      for(int i = 0; i < 26; ++i) ans += (query(BIT[i], aux1, aux2)%2);
      cout << ((ans > 1)?"no\n":"yes\n");
    }
  }




  return 0;
}
