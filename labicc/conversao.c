#include <stdio.h>

int main(){
  int entrada, horas, minutos, segundos;
  scanf("%d", &entrada);
  horas = entrada/3600;
  entrada -= horas*3600;
  minutos = entrada/60;
  entrada -= minutos*60;
  segundos = entrada;
  printf("%dh %dm %ds\n", horas, minutos, segundos);



  return 0;
}
