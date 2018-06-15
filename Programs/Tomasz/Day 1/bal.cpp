#include <bits/stdc++.h>

using namespace std;

int ft[1 << 18], A[200100], B[200100];

bool comp(int a, int b){
  return a > b;
}

void upd(int x, int val){
  for(; x < 200010; x += x&-x)  ft[x] += val;
}

int query(int x){
  int ret = 0;
  for(x > 0; x -= x&-x) ret += ft[x];
  return ret;
}

int ft_search1(int val){
  int sum = 0, ret = 0;
  for(int pot = 18; pot > -1; --pot){
    if(sum + ft[1 << pot] > val)  continue;
    ret += (1 << pot), sum += ft[1 << pot];
  }
  return ret + 1;
}


int ft_search2(int val, int p){

}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  bool vdc = 1;
  int n, m, a, b, left, right, val;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i)
    cin >> A[i];
  for(int i = 1; i <= m; ++i)
    cin >> B[i];

  sort(B + 1, B + m + 1);
  sort(A + 1, A + n + 1, comp);

  for(int i = 0; i <= m; ++i)
    if(B[i] > n){
      cout << "NIE\n";
      return 0;
    }

  for(int i = 1; i <= m; ++i){
    val = A[B[i]] + sum(B[i]);

    if(val < 0){
      vdc = 0;
      break;
    }

    right = ft_search(query(b)); //ultimo cara com valor a[b]
    left = ft_search(query(b + 1)) + 1; //primeiro cara com valor a[b]
    upd(1, -1);
    upd(left, 1);
    upd(, -1);
    upd(right + 1, 1);
  }
  cout << "TAK\n";

  return 0;
}
