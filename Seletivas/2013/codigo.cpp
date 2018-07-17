#include <bits/stdc++.h>

using namespace std;

int ft[100100];

void upd(int a){
  for(; a < 100099; a += a&-a) ++ft[a];
}

int query(int a){
  int ret;
  ret = ft[100099];
  for(int i = 100099; i > 0; i -= i&-i)  ret += ft[i];
  for(; a > 0; a -= a&-a)  ret -= ft[a];
  return ret;
}

int main(){
  int n, a;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a);
    printf("%d%s", query(a), ((i == n - 1)?"\n":" ")) ;
    upd(a);
  }

  return 0;
}
