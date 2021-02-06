#include <cstdio>
#include <iostream>

using namespace std;

long long int fib[1000100];
int main(){
   ios_base::sync_with_stdio(0);
   fib[0] = fib[1] = 1;
   for(int i = 3; i < 1000001; ++i){
      for(int j = 2; j < 100001; ++j){
         fib[j] = (fib[j - 1] + fib[j - 2])%i;
         if(fib[j] == fib[j - 1] && fib[j] == 1){
               cout << (j - 1) << ", ";
               break;
         }
      }
   }





   return 0;
}
