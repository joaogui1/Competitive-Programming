#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define  lim 1e-9
using namespace std;
typedef pair <long long int, long long int> pii;

bool cross(pii a, pii b, int r){
   long long int ret = ((a.first)*(b.second) - (b.first)*(a.second))*((a.first)*(b.second) - (b.first)*(a.second));
   return (ret <= r*r*((a.first*a.first) + (a.second*a.second)));
}
int main(){
   int n, cont = 0;
   long long int r;
   pii circle, p1, p2, ab, ac;
   scanf("%d %lld %lld %lld", &n, &circle.first, &circle.second, &r);
   while(n--){
      scanf("%lld %lld %lld %lld", &p1.first, &p1.second, &p2.first, &p2.second);
      ab.first = p2.first - p1.first;
      ab.second = p2.second - p1.second;
      ac.first = circle.first - p1.first;
      ac.second = circle.second - p1.second;
      if(cross(ab, ac, r))  ++cont;
   }
   printf("%d\n", cont);
   return 0;
}
