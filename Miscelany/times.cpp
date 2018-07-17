#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <algorithm>
using namespace std;

typedef struct{
        int h;
        int time;
        char nome[1010];
}jogador; 

bool compara(jogador a, jogador b){
     if(a.h > b.h) return true;
     if(a.h < b.h) return false;        
}

jogador jog[10010];

int main(){
    
    int n,t;
        
    scanf("%d %d",&n,&t);
    
    for(int i=1; i<=n;i++){
        scanf("%s %d",&jog[i].nome,&jog[i].h);    
    }
    
    sort(jog+1,jog+n+1,compara);
    
    for(int i=1; i<=t; i++){        
        
        printf("Time %d\n",i);
        
        string time[10010];
        int aux=0;
        
        for(int j=i; j<=n; j=j+t){
            aux++;
            time[aux]=jog[j].nome;             
        }
        
        sort(time+1,time+aux+1);
        
        for(int j=1; j<=aux; j++)
                printf("%s\n",time[j].c_str() );
        
        printf("\n");
    }
    
    system("pause");
        
    return 0;
}
