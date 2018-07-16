#include <stdio.h>
#include <stdlib.h>

int campo[1010][1010];

int main(){

    int x,y;
    int resposta;
    
    scanf("%d %d",&x,&y);
    
    resposta= x % y;
    
    scanf("%d\n",resposta);
}
