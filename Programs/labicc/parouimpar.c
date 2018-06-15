#include <stdio.h>

int main(){
  int a, b, c;
  char tp, op;
  scanf(" %c", &tp);
  switch(tp){
    case 'E':
      scanf(" %c %d %d", &op, &a, &b);
      break;
    case 'I':
      scanf("%d %c %d", &a, &op, &b);
      break;
    default:
      scanf("%d %d %c", &a, &b, &op);
      break;
  }
  switch(op){
    case '+':
      c = a + b;
      break;
    case '-':
      c = a - b;
      break;
    case 'x':
      c = a*b;
      break;
    default:
      c = a/b;
      break;
  }
  if(c%2 == 0)  printf("O resultado %d eh par.\n", c);
  else  printf("O resultado %d eh impar.\n", c);


  return 0;
}
