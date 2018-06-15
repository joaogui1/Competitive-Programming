#include <stdio.h>

float mean(float *v, int n){
  float med = 0;
  for(int i = 0; i < n; ++i)  med += v[i];
  return med/n;
}

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  float vet[n][m];
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j)
      scanf("%f", &vet[i][j]);
    printf("%f\n", mean(vet[i], m));
  }

  return 0;
}
