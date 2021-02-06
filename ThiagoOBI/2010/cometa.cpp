#include <bits/stdc++.h>

using namespace std;

set <int> s;

void pre(){
  s.insert(1986);
  for(;*(--s.end()) < 10010; s.insert(*(--s.end()) + 76));
  return;
}

int main(){
  pre();
  int n;
  scanf("%d", &n);
  printf("%d\n", *s.upper_bound(n));

  return 0;
}
