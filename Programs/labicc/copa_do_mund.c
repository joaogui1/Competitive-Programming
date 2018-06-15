#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char nome[101];
  int marca, receb, pts;
}selecao;

selecao cria(){
  selecao ret;
  strcpy(ret.nome, "");
  ret.marca = ret.receb = ret.pts = 0;
  return ret;
}

int find_best(selecao *times){
  int melhor = 0;
  for(int i = 1; i < 4; ++i){
    if(times[i].pts > times[melhor].pts)  melhor = i;
    else if(times[i].pts > times[melhor].pts){
      if(times[i].marca - times[i].receb > times[melhor].marca - times[melhor].receb)  melhor = i;
      else if(times[i].marca - times[i].receb == times[melhor].marca - times[melhor].receb){
        if(strcmp(times[i].nome, times[melhor].nome) < 0) melhor = i;
      }
    }
  }
  return melhor;
}

void read_file(FILE *in, selecao* times){
  int aux[2], idx[2];
  char aus[2][100];
  for(int i = 0; i < 6; ++i){
    fscanf(in, "%s %d %s %d", aus[0], &aux[0], aus[1], &aux[1]);

    for(int k = 0; k < 2; ++k){

      for(int j = 0; j < 4; ++j){
        if(strlen(times[j].nome) == 0){
          strcpy(times[j].nome, aus[k]);
          idx[k] = j;
          break;
        }

        if(strcmp(aus[k], times[j].nome) == 0){
          idx[k] = j;
          break;
        }
      }
    }

    for(int k = 0; k < 2; ++k){
      times[idx[k]].marca += aux[k];
      times[idx[k]].receb += aux[k^1];
    }
    if(aux[0] > aux[1]) times[idx[0]].pts += 3;
    else if(aux[0] < aux[1])  times[idx[1]].pts += 3;
    else  ++times[idx[0]].pts, ++times[idx[1]].pts;

  }
}

int main(int argc, char const *argv[]) {
  char entrada[100];
  scanf("%s", entrada);
  FILE *in = fopen(entrada, "r");
  FILE *out = fopen("saida.txt", "w");

  selecao times[4];
  int melhor = 0;

  for(int i = 0; i < 4; ++i)  times[i] = cria();

  read_file(in, times);

  melhor = find_best(times);
  printf("%s\t%d\t%d\t%d\t%d\n", times[melhor].nome, times[melhor].marca, times[melhor].receb, times[melhor].marca - times[melhor].receb, times[melhor].pts);
  for(int i = 0; i < 4; ++i)
    fprintf(out, "%s\t%d\t%d\t%d\t%d\n", times[i].nome, times[i].marca, times[i].receb, times[i].marca - times[i].receb, times[i].pts);
  return 0;
}
