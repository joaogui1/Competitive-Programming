#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  double x, pot = 1, fat = 1, ans = 0;
  scanf("%lf %d", &x, &n);
  for(int i = 0; i < n; ++i){
    ans += pot/fat;
    fat *= (i+1);
    pot *= x;
  }
  ans -= exp(x);
  if(ans < 0) ans *= -1;
  printf("O erro obtido eh %.6e\n", ans);


  return 0;
}
