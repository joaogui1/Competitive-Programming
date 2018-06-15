#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_X 1040
#define MAX_Y 1040

int bit[MAX_X][MAX_Y];

int sum(int x, int y_fixo){
   int soma = 0;
   while (x > 0){
      int y = y_fixo;
      while(y > 0){
         soma += bit[x][y];
      	y -= (y & -y);
      }
         x -= (x & -x);
   }
   return soma;
}

void insere(int x , int y_fixo , int valor){
	while (x <= MAX_X){
      int y = y_fixo;
		while (y <= MAX_Y){
			bit[x][y] += valor;
			y += (y & -y);
		}
		x += (x & -x);
	}
}


int soma_intervalo(int a, int b,int x,int y){
       return ( sum(x,y) - sum(x,b-1) - sum(a-1,y) + sum(a-1,b-1) );
}

int main(){
       int s,op, x, y, a, l, b,r, t;
       while(1){
          scanf("%d", &op);
          if(op == 3)   break;
          if(op == 0){
             scanf("%d", &s);
          }
          if(op == 1){
             scanf("%d%d%d", &x, &y, &a);
             insere(x+1, y+1, a);
          }
          if(op == 2){
             scanf("%d %d %d %d", &l, &b, &r, &t);
             printf("%d\n", soma_intervalo(l+1, b+1, r+1, t+1));
          }
       }


       return 0;
}
