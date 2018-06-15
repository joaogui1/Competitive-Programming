#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include<algorithm>
char s[40];
using namespace std;
int main() {
    int a ,b, c;scanf("%d%d%d", &a, &b, &c);
    int* pa=&a;int* pb=&b;int* pc=&c;
    printf("%p\n%p\n%p\n", pa,pb,pc);printf("%d\n%d\n%d\n", a, b, c);
    printf("%p\n%p\n%p\n", &a,&b,&c);printf("%d\n%d\n%d\n", a, b, c);
    return 0;
}
