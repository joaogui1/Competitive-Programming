#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>
#include <math.h>

//NEGLIGENCIAS!!!

int main(){
    
    scanf("%s",&nome);
    
    scanf(" %c",&caractere);
    
    //STRING--------------------------
    strcpy(nome1,nome2); // nome1=nome2
    strcat(nome1,nome2); //nome1 += nome2
    strlen(nome1); //retorna tamanho string
    strcmp(nome1,nome2); //  compara duas strings
    

    //MATH--------------------------
    pow(x,y); //x^y  
    sin(x);//seno de x em radianos
    cos(x);//cosseno de x em radianos  
    log10(x);//logaritmo   
    sqrt(x);//raiz de x    
    ceil(x); //parte inteira para cima
    floor(x);// parte inteira para baixo
    
    
    //CTYPE--------------------------    
    isalpha(c); //veh se eh letra    
    isdigit(c); //veh se eh numero
    islower(c);//checa se minusculo
    isupper(c);//checa se eh maisculo
    
    return 0;
}
