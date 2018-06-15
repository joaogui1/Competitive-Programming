#include <bits/stdc++.h>

using namespace std;

int main(){
  int x, y, f1[2], f2[2];
  scanf("%d %d", &x, &y);
  scanf("%d %d", &f1[0], &f1[1]);
  scanf("%d %d", &f2[0], &f2[1]);
  for(int i = 0; i < 2; ++i)
    for(int j = 0; j < 2; ++j)
      if((f1[i] + f2[j] <= x && max(f1[1 - i], f2[1 - j]) <= y) || (f1[i] + f2[j] <= y && max(f1[1 - i], f2[1 - j]) <= x)){
        printf("S\n");
        return 0;
      }
  printf("N\n");


  return 0;
}
