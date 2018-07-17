#include <stdio.h>
#include <stdlib.h>

int *my_alloc (int n){
  int *vetor;
  vetor = malloc(n*sizeof(int));
  return vetor;
}

int *merge(int n, int v1[], int m, int v2[]){
  int minimo = (n < m)?n:m;
  int *v3;
  v3 = my_alloc(n + m);
  for(int i = 0; i < minimo; ++i){
    v3[2*i] = v1[i];
    v3[2*i + 1] = v2[i];
  }
  for(int i = n; i < m; ++i)  v3[n + i] = v2[i];
  for(int i = m; i < n; ++i)  v3[m + i] = v1[i];
  return v3;
}


void print(int n, int v[]){
  for(int i = 0; i < n; ++i)
    printf("%d ", v[i]);
  printf("\n");
}

void read (int n, int v[]){
  for(int i = 0; i < n; ++i)
    scanf("%d", &v[i]);
  return;
}

int main(){
  int n, m, *v1, *v2, *v3;
  scanf("%d %d", &n, &m);
  v1 = my_alloc(n);
  v2 = my_alloc(m);
  read(n, v1);
  read(m, v2);
  v3 = merge(n, v1, m, v2);
  print(n + m, v3);
  free(v1);
  free(v2);
  free(v3);


  return 0;
}
