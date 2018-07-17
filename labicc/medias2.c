#include <stdio.h>


void print(int n, int m, float mat[20][20]){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j)
        printf("%f\t", mat[i][j]);
    printf("\n");
  }
  return;
}

float mean(float *v, int n){
  float med = 0;
  for(int i = 0; i < n; ++i)  med += v[i];

  return med/n;
}

void augment(int n, int m, float mat[20][20]){
  for(int i = 0; i < n; ++i){
    mat[i][m - 1] = mean(mat[i], m - 1);

  }
}

void scan(int n, int m, float mat[20][20]){
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m - 1; ++j)
    scanf("%f", &mat[i][j]);
  augment(n, m, mat);
  print(n, m, mat);
  return;
}

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  float mat[20][20];
  scan(n, m + 1, mat);




  return 0;
}
