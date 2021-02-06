#include <cstdio>
#include <cstdlib>

int main(){
   int r, a, b, c;
   scanf("%d %d %d %d", &a, &b, &c, &r);
   printf("%s\n",(4*r*r >= a*a + b*b + c*c)?"S":"N");
   return 0;
}
