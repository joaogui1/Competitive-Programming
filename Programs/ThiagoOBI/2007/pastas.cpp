#include <bits/stdc++.h>

using namespace std;

int freq[1024];

int main(){
  int p, n, a, mx = 0, mi = (1 << 20);
  scanf("%d %d", &p, &n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a);
    ++freq[a];
  }
  for(int i = 1; i <= p; ++i)
    mx = max(mx, freq[i]), mi = min(mi, freq[i]);
  for(int i = 1; i < p; ++i)
    if(freq[i + 1] > freq[i]) mx = -1;
  printf("%s\n", (mx - mi > 1 || mx - mi < 0)?"N":"S");

  return 0;
}
