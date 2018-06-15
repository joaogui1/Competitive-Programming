#include <bits/stdc++.h>

using namespace std;

int main(){
  long long int ret[3][3];
  for(int i = 0; i < 3; ++i){
    scanf("%lld %lld", &ret[i][0], &ret[i][1]);
    if(ret[i][0] < ret[i][1]) swap(ret[i][0], ret[i][1]);
  }
  if(ret[0][0]*ret[0][1] + ret[1][0]*ret[1][1] < ret[2][0]*ret[2][1])
    printf("N\n");

  else if(ret[0][0] >= ret[2][0] && ret[0][1] >= ret[2][1])
    printf("S\n");

  else if(ret[1][0] >= ret[2][0] && ret[1][1] >= ret[2][1])
    printf("S\n");

  else if(ret[1][0] + ret[0][0] >= ret[2][0] && min(ret[1][1], ret[0][1]) >= ret[2][1])
    printf("S\n");

  else if(ret[1][0] + ret[0][1] >= ret[2][0] && min(ret[1][1], ret[0][0]) >= ret[2][1])
    printf("S\n");

  else if(ret[1][1] + ret[0][0] >= ret[2][0] && min(ret[1][0], ret[0][1]) >= ret[2][1])
    printf("S\n");

  else if(ret[1][1] + ret[0][1] >= ret[2][0] && min(ret[1][0], ret[0][0]) >= ret[2][1])
    printf("S\n");

  else
    printf("N\n");



  return 0;
}
