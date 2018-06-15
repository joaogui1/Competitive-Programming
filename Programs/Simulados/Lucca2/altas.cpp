#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int n, k;
long long f(int x){
   long long int ans = 0, aux = 1;
   for(int i = 1; i <= k; ++i){
      //cout << x << " " << i << " " << aux << endl;
      aux*=(x- i + 1);
      aux /= i;
      //cout << "   " << x << " " << i << " " << aux << endl;
      ans += aux;
      //cout << "   " << x << " " << i << " "<< ans << endl;
      if(ans > n)   break;
   }
   return ans;
}
int main(){
   int mid, beg, end, test;
   scanf("%d %d", &n, &k); //n "floors", k "eggs"
   test = ceil(log2(n));
   beg = 0; end = n;
   if(k >= test)  printf("%d\n", test);
   else{
      while(end - beg > 1){
         mid = (end + beg)/2;
         if(f(mid) < n) beg = mid;
         else  end = mid;
      }
      printf("%d\n", end);
   }
   return 0;
}
