#include <bits/stdc++.h>

int dx[8] = {2, 2, -1, 1, -2, -2, -1, 1}, dy[8] = {1, -1, 2, 2, 1, -1, -2, -2};

int main(){
  int n, posi, movs, posii;
  char posc;
  scanf("%d", &n);
  while(n--){
    movs = 0;
    scanf(" %c%d", &posc, &posi);
    posii = (posc - 'a' + 1);
    for(int i = 0; i < 8; ++i)  movs += (posi + dx[i] > 0 && posi + dx[i] < 9 && posii + dy[i] > 0 && posii + dy[i] < 9);

    printf("%d\n", movs);
  }


  return 0;
}
