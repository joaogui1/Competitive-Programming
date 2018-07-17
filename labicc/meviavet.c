#include <stdio.h>

float mean(float *v, int n){
  float med = 0;
  for(int i = 0; i < n; ++i)  med += v[i];
  return med/n;
}

int main(){
  int n;
  scanf("%d", &n);
  float vet[n];
  for(int i = 0; i < n; ++i)
    scanf("%f", &vet[i]);
  printf("%f\n", mean(vet, n));


  return 0;
}
