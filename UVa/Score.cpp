#include <cmath>
#include <cstdio>
#include "string"
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define debug(a, b, c, d ,e)  std::cout << a << " " << b << " " << c << " " << d << " " << e
#define INF (1 << 30)
#define Left(x) 2*x
#define Right(x) 2*x + 1
#define Father(x) (x%2==0)?x/2:(x-1)/2
using namespace std;

int main(){
   int n, cont, ans;
   string input;
   scanf("%d", &n);
   while(n--){
      cont =  ans = 0;
      cin >> input;
      for(int i = 0; i < input.size(); ++i){
         if(input[i] == 'X')  cont = 0;
         else  ++cont;
         ans += cont;
      }
      printf("%d\n", ans);
   }

   return 0;
}
