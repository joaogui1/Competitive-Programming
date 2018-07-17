#include <cmath>
#include <cstdio>

int n, k;

long long int f(int x){
   long long int ret = 0, aux = 1;
   for(int i = 1; i <= k; ++i){
      aux *= (x - i + 1);
      aux /= i;
      ret += aux;

      if(ret >= n)   break;
   }
   return ret;
}
int main(){
   scanf("%d %d", &n, &k);
   if(k >= ceil(log2(n)))  printf("%d\n", int(ceil(log2(n))));
   else{
      int beg = 0, end = n, mid;
      while(end - beg > 1){
         mid = (end + beg)/2;
         if(f(mid) < n) beg = mid;
         else  end = mid;
      }
      printf("%d\n", end);
   }
   return 0;
}
