#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#define debug(a, b, c, d ,e)  std::cout << a << " " << b << " " << c << " " << d << " " << e
#define INF (1 << 30)
#define SET(obj, a) memset(obj, a, sizeof(obj))
using namespace std;
int zeros[3], ones[3];
int main(){
   int n, cont, ans, marks, change, cas = 0;
   string input, output;
   scanf("%d", &n);
   while(n--){
      cont =  ans = 0;
      cin >> input >> output;
      SET(zeros, 0);SET(ones, 0);
      for(int i = 0; i < input.size(); ++i){ //descobre o numero de 1 e 0 em cada
         if(input[i] == '1')  ++ones[0];
         else if(input[i] == '0')  ++zeros[0];
         if(output[i] == '1')  ++ones[1];
         else if(output[i] == '0')  ++zeros[1];
      }
      marks = input.size() - ones[0] - zeros[0];
      if(ones[0] > ones[1] || input.size() != output.size()) ans = -1;
      else{
         change = 1;
         for(int i = 0; i < input.size(); ++i){
            if(input[i] == '?' && output[i] == '0'){
               input[i] = '0';
               ++zeros[0];++ans; //teve uma mudanca
            }
         }
         for(int i = 0; i < input.size(); ++i){
            if(input[i] == '?' && zeros[0] < zeros[1]){
               input[i] = '0';
               ++zeros[0];++ans; //teve uma mudanca
            }
            else if(input[i] == '?'){
               input[i] = '1';
               ++ones[1];++ans;
            }
         }
         for(int i = 0; i < input.size() && zeros[0] > zeros[1]; ++i){
            if(input[i] == '0' && output[i] == '1'){
               input[i] = '1';
               --zeros[0];++ans; //teve uma mudanca
            }
         }
         for(int i = 0; i < input.size(); ++i){
            if(input[i] != output[i]){
               ans += change;
               change = change xor 1; //turns change on and off
            }
         }
      }
      printf("Case %d: %d\n", ++cas, ans);
   }

   return 0;
}
