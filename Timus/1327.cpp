#include <bits/stdc++.h>

int main(){
  int a, b;
  scanf("%d %d", &a, &b);
  if(b%2 == 1)
    printf("%d\n", (b - a)/2 + 1);
  else
      printf("%d\n", (b - a + 1)/2);


  return 0;
}
