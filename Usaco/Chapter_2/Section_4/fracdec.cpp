/*
ID: joaogui1
LANG: C++
TASK: fracdec
*/
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#define debug(a, b, c, d ,e)  std::cout << a << " " << b << " " << c << " " << d << " " << e
#define INF (1 << 30)
using namespace std;
string num;
bool tem_diz(int n){
   while(n != 1 &&(n%2 == 0 || n%5 == 0)){
      if(n%2 == 0)   n/=2;
      if(n%5 == 0)   n/=5;
   }
   return !(n == 1);
}
void long_div(int a, int b){
   int cont = 0;
   bool dot = 1;
   while(a != 0 && cont < 1001){
      stringstream convert;
      convert << a/b;
      num += convert.str();
      a = a%b;
      if(a < b){
         a *= 10;
         if(dot)  num += '.';
         dot = 0;
      }
      ++cont;
   }
   return;
}
int main(){
   int a, b, c;
   ifstream fin("fracdec.in");
   ofstream fout("fracdec.out");
   cin >> a >> b;
   long_div(a, b);
   if(num[num.size() - 1] == '.')   num += '0';
   if(tem_diz(b)){
      int dot_loc;
      for(dot_loc = 0; dot_loc < num.size(); ++dot_loc)
         if(num[dot_loc] == '.') break;
      for(int i = dot_loc + 1; i < num.size(); ++i){
         for(int j = 1; j <= (num.size() - i - 1)/2; ++j){
            if(num.compare(i, j, num, i + j, j) == 0){
               for(int k = i + j; k > i; --k)
                  num[k] = num[k-1];
               num[i] = '(';
               num[i + j + 1] = ')';
               i = num.size();
               break;
            }
         }
      }
   }
   for(c = 1; c <= num.size(); ++c){
      fout << num[c-1];
      if(num[c-1] == ')') break;
      if(c%76 == 0) fout << endl;
   }
   fout << endl;
   return 0;
}
