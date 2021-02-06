#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int x, y, l1, h1, l2, h2;
    bool vdc = 0;
    scanf("%d %d %d %d %d %d", &x, &y, &l1, &h1, &l2, &h2);
    if(x >= l1 + l2 && y >= max(h1, h2))    printf("S\n");
    else if(x >= l1 + h2 && y >= max(h1, l2))    printf("S\n");
    else if(x >= h1 + l2 && y >= max(l1, h2))    printf("S\n");
    else if(x >= h1 + h2 && y >= max(l1, l2))    printf("S\n");
    else if(y >= l1 + l2 && x >= max(h1, h2))    printf("S\n");
    else if(y >= l1 + h2 && x >= max(h1, l2))    printf("S\n");
    else if(y >= h1 + l2 && x >= max(l1, h2))    printf("S\n");
    else if(y >= h1 + h2 && x >= max(l1, l2))    printf("S\n");
    else printf("N\n");



    return 0;
}
