#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define SET(obj, a) memset(obj, a, sizeof(obj))
#define INF 0x3f3f3f3f
using namespace std;
long long int dot_p(int a[2], int b[2]){
   return a[0]*b[0] + a[1]*b[1];
}
int n, ans;
double xc, yc, r, delta=0.00000000001;

int main(){
   double x1, y1, x2, y2, a, p, q, b;
	scanf("%d %lf %lf %lf", &n, &xc, &yc, &r);
	for(int i = 1; i <= n; ++i){
		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		if(x1 == x2){
                if(abs(xc-x1)<=r) ++ans;
                continue;
      }
		if(y1 == y2){
        if(abs(yc-y1)<=r) ++ans;
        continue;
     }
   	a = (y2 - y1)/(x2 - x1), b=-a*x1+y1;
   	p = yc - a*xc - b, q = xc - (yc - b)/a;
   	if(p == q && p == 0){
   		++ans;
   		continue;
   	}
   	double d = abs(p*q)/sqrt(p*p + q*q);
   	if(d <= r + delta) ++ans;
   }

	printf("%d\n", ans);

	return 0;
}
