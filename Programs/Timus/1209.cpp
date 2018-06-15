#include <bits/stdc++.h>

using namespace std;

set <long long int> tri;
int main(){
  long long int n, k;
  scanf("%lld", &n);
  for(long long int i = 0LL; i < (1LL << 17LL); ++i)  tri.insert((i*i + i)/2 + 1);
  while(n--){
    scanf("%lld", &k);
    if(tri.count(k))  printf("1");
    else  printf("0");
    if(n) printf(" ");
  }
  printf("\n");

  return 0;
}
