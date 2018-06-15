#include <stdio.h>

int main(){
  int n, aux, freq[11] = {0};
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &aux);
    ++freq[aux];
  }
  for(int i = 0; i < 11; ++i)
    printf("Nota %d: %d\n", i, freq[i]);

  return 0;
}
