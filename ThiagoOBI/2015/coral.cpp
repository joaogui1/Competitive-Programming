#include <bits/stdc++.h>

using namespace std;

int v[4];
char ans[2] = {'F', 'V'};

int main(){
  for(int i = 0; i < 4; ++i)  scanf("%d", &v[i]);
  printf("%c\n", ans[v[0] == v[2] || v[1] == v[3]]);
  return 0;
}
