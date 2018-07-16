#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
using namespace std;





#include <math.h>




double x;

........

ceil(x);














if('a' <= c && c<= 'z')








int main(){
    
    int n;
    int vetor[1010];
    
    scanf("%d",&n);
    
    for(int i=1; i<=n; i++) 
            scanf("%d",&vetor[i]);
    
    for(int i=1; i<=n; i++) 
            vetor[i]=vetor[i]*(-1);
    
    sort(vetor+1, vetor+n+1);
    
    for(int i=1; i<=n; i++) 
            vetor[i]=vetor[i]*(-1);
    
    for(int i=1; i<=n; i++) 
            printf("%d ",vetor[i]);
    
    system("pause");
    
    return 0;
}
