#include <stdio.h>

int main(){
  float nota1, nota2, nota3, media;
  scanf("%f %f %f", &nota1, &nota2, &nota3);
  media = 0.35*nota1 + nota2*0.35 + nota3*0.30;
  printf("%f\n", media);



  return 0;
}
