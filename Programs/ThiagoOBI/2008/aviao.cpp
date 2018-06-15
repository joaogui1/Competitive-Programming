#include <bits/stdc++.h>

using namespace std;

int main(){
  int f, c, e, b, tot;
  scanf("%d %d %d %d", &f, &c, &e, &b);
  tot = f*c;
  if(tot < b + (e - 1)*c) printf("PROXIMO VOO\n");
  else{
    printf("%d ", e + (b - 1)/c);
    printf("%c\n", 'A' + ((b%c) + c - 1)%c);
  }


  return 0;
}
