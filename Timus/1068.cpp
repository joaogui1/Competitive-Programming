#include <bits/stdc++.h>

int main(){
  long long int n;
  scanf("%lld", &n);
  if(n < 1LL){
    printf("%lld\n", 1 - n*(n-1)/2);
  }
  else
    printf("%lld\n", n*(n+1)/2);


  return 0;
}
