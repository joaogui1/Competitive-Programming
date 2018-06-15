#include <bits/stdc++.h>

int main(){
  int n;
  scanf("%d", &n);

  if(n%4 == 3 || n%4 == 0)  printf("black\n");
  else  printf("grimy\n");

  return 0;
}
