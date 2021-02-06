#include <bits/stdc++.h>

using namespace std;

int main(){
  long long int G[6][6], s[5], ans = 1LL << 15LL, ans_ind = 1, test = 0;
  for(int i = 0; i < 5; ++i)
    for(int j = 0; j < 5; ++j)  scanf("%lld", &G[i][j]);

  s[0] = G[0][1] + G[1][2] + G[2][3] + G[3][4];
  s[1] = G[0][2] + G[1][2] + G[1][3] + G[3][4];
  s[2] = G[0][2] + G[3][2] + G[1][3] + G[1][4];
  s[3] = G[0][3] + G[3][2] + G[2][1] + G[1][4];

  if(s[0] == min(min(s[0], s[1]), min(s[2], s[3])))
    printf("%lld\n1 2 3 4 5\n", s[0]);
  else if(s[1] == min(min(s[0], s[1]), min(s[2], s[3])))
    printf("%lld\n1 3 2 4 5\n", s[1]);
  else if(s[2] == min(min(s[0], s[1]), min(s[2], s[3])))
    printf("%lld\n1 3 4 2 5\n", s[2]);
  else
    printf("%lld\n1 4 3 2 5\n", s[3]);
  return 0;
}
