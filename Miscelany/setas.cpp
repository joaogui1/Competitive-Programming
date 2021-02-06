#include <cstdio>
#include <cstdlib>
#include <cstring>
#define BAIXO 1
#define CIMA 2
#define ESQUERDA 3
#define DIREITA 4
int tabuleiro[510][510];
int nao_seguro[510][510];
int mark[510][510];
void dfs(int verticey, int verticex){
     nao_seguro[verticey][verticex]=1;
     mark[verticey][verticex]=1;
     if(!nao_seguro[verticey][verticex-1] && tabuleiro[verticey][verticex-1]==DIREITA)dfs(verticey,verticex-1);
     if(!nao_seguro[verticey][verticex+1] && tabuleiro[verticey][verticex+1]==ESQUERDA)dfs(verticey,verticex+1);
     if(!nao_seguro[verticey-1][verticex] && tabuleiro[verticey-1][verticex]==BAIXO)dfs(verticey-1,verticex);
     if(!nao_seguro[verticey+1][verticex] && tabuleiro[verticey+1][verticex]==CIMA)dfs(verticey+1,verticex);
     }
int main(){
    int n, posx=1, posy=1,seguro=0;
    char c;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                    scanf(" %c", &c);
                    if(c=='V'){
                               tabuleiro[i][j]=BAIXO;
                               if(i+1>n)nao_seguro[i][j]=1;
                                               
                    }
                    else if(c=='A'){
                         tabuleiro[i][j]=CIMA;
                         if(i-1==0)nao_seguro[i][j]=1;
                         }
                    else if(c=='>'){
                         tabuleiro[i][j]=DIREITA;
                         if(j+1>n)nao_seguro[i][j]=1;
                         }
                    else if(c=='<'){
                         tabuleiro[i][j]=ESQUERDA;
                         if(j-1==0)nao_seguro[i][j]=1;
                         }
                    }
            }

    
    for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                    if(nao_seguro[i][j] && !mark[i][j])dfs(i,j);
                    }
            }
   
    for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                    if(!nao_seguro[i][j])seguro++;
                    }
            }
    printf("%d\n", seguro);     
    return 0;
    }
