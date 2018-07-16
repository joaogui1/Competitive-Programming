#include <cstdio>
#include <cstdlib>
#include <cstring>
char palavras[1010];
int mark[1010];
int main(){
           int aux=1, tam=0,num=1;
           double palavras_com_char=0.0;
           
           char c;
           scanf(" %c", &c);
           scanf(" %[^\n]", &palavras);
           for(int i=0; i<1010; i++){
                   if(palavras[i]==palavras[1009] && palavras[i+1]==palavras[1009]){
                                     tam=i;
                                     break;
                                     }
                   else if(palavras[i]==' ' && palavras[i+1]!=' ')num++;
                   }
           if(palavras[0]==' ')num--;
           for(int i=0; i<tam; i++){
                   if(!mark[aux] && palavras[i]==c){
                                 mark[aux]=1;
                                 palavras_com_char++;
                                 }
                   else if(palavras[i]==' ')aux++;
                   }
           palavras_com_char=100*(palavras_com_char/num);
           printf("%0.1lf\n", palavras_com_char);
    
           return 0;
    }

