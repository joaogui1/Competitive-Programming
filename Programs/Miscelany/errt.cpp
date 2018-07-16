#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

typedef struct{
int med_o;
int med_p;
int med_b;
int id;
}dados;

int paises,modalidades;
dados pais[100];

int crescente(dados a,dados b){
    if(a.med_o>b.med_o)return 1;
    if(a.med_o<b.med_o)return 0;

    if(a.med_p>b.med_p)return 1;
    if(a.med_p<b.med_p)return 0;

    if(a.med_b>b.med_b)return 1;
    if(a.med_b<b.med_b)return 0;

    if(a.id>b.id)return 1;
    if(a.id<b.id)return 0;

    }


int k;

int main (){
    
    scanf("%d %d",&paises,&modalidades);

    for(int i=1;i<=modalidades;i++){
        for(int j=1;j<=3;j++){
            scanf("%d",&k);
            if(j==1){pais[k].med_o++,pais[k].id=k;}
            if(j==2){pais[k].med_p++,pais[k].id=k;}
            if(j==3){pais[k].med_b++,pais[k].id=k;}
        }
    }
    
    std::sort(pais+1,pais+paises+1,crescente);
   
    printf("%d %d %d",pais[1].id,pais[2].id,pais[3].id);
    
    return 0;}
