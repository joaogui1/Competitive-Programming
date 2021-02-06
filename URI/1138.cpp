#include <bits/stdc++.h>

using namespace std;

vector <int> va, vb;
int pot10[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int nines(int n){
  for(int i = 1; i < 9; ++i)
    if((n + 1)%pot10[i] != 0){
      if(n > pot10[i - 1] - 1)  return i - 1;
      else  return i - 2;
    }
  return 7;
}

void cnta(int a){
  int n;
  va.assign(10, 0);
  for(; a; a -= pot10[n]){
    n = nines(a);
    for(int i = a/pot10[n]; i; i /= 10)
      va[i%10] += pot10[n];
    if(n)
      for(int i = 0; i < 10; ++i)
        va[i] += pot10[n - 1]*n;
  }
  return;
}

void cntb(int a){
  int n;
  vb.assign(10, 0);
  for(; a; a -= pot10[n]){
    n = nines(a);
    for(int i = a/pot10[n]; i; i /= 10)
      vb[i%10] += pot10[n];
    if(n)
      for(int i = 0; i < 10; ++i)
        vb[i] += pot10[n - 1]*n;
  }
  return;
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int a, b;
  while(cin >> a >> b){
    if(a + b == 0)  return 0;
    cnta(a - 1), cntb(b);
    for(int i = 0; i < 10; ++i) cout << vb[i] - va[i] << " \n"[i == 9];
  }
  return 0;
}
