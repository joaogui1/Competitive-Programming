#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
   int ans = 0, n;
   scanf("%d", &n);
   string input;
   cin >> input;
   for(int i = 0; i < input.size(); ++i){
      if(input[i] == 'P' || input[i] == 'C')  ans += 2;
      if(input[i] == 'A')  ans += 1;
   }
   printf("%d\n", ans);

   return 0;
}
