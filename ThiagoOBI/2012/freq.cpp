#include <bits/stdc++.h>

using namespace std;

set <int> s;

int main(){
  int n, a;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a);
    s.insert(a);
  }
  printf("%d\n", s.size());
  return 0;
}
