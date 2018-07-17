#include <stdio.h>

char meses[13][25] = {"Erro na entrada", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

int dias(int mes, int ano){
  if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){ //Janeiro, Marco, Maio etc
    return 31;
  }
  else if(mes == 2){ //Fevereiro
    if(ano%400 == 0)  return 29;
    if(ano%100 == 0)  return 28;
    if(ano%4 == 0)  return 29;
    return 28;
  }
  else  return 30;
}

int main(){
  int mes, ano;
  scanf("%d %d", &mes, &ano);
  if(mes < 1 || mes > 12 || ano < 1){
    printf("%s\n", meses[0]);
    return 0;
  }
  printf("%s de %d teve %d dias\n", meses[mes], ano, dias(mes, ano));


  return 0;
}
