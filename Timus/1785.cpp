#include <bits/stdc++.h>

int main(){
    int n;
    scanf("%d", &n);

    if(n < 5) printf("few\n");
    else if(n < 10) printf("several\n");
    else if(n < 20) printf("pack\n");
    else if(n < 50) printf("lots\n");
    else if(n < 100) printf("horde\n");
    else if(n < 250) printf("throng\n");
    else if(n < 250) printf("throng\n");
    else if(n < 500) printf("swarm\n");
    else if(n < 1000) printf("zounds\n");
    else printf("legion\n");
  
  return 0;
}
