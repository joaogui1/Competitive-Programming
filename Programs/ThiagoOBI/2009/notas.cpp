#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  if(n < 1) printf("E\n");
  else if(n < 36) printf("D\n");
  else if(n < 61) printf("C\n");
  else if(n < 86) printf("B\n");
  else if(n < 101)  printf("A\n");



  return 0;
}
