#include <bits/stdc++.h>

using namespace std;

int main(){
  int h, min, ans;
  while(scanf("%d:%d", &h, &min) != EOF){
    ++h;
    ans =(h*60 + min > 480)?(h*60 + min - 480):(0);

    printf("Atraso maximo: %d\n", ans);
  }


  return 0;
}
