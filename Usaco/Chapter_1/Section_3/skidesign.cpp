/*
ID: joaogui1
LANG: C++
TASK: skidesign
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
vector <int> entrada;
int heights[110], ans = 1000000000;
int main(){
   int n, aux, Max = 0, Min = 110, low, price;
   ifstream fin ("skidesign.in");
   ofstream fout ("skidesign.out");
   fin >> n;
   for(int i = 0; i < n; ++i){
      fin >> aux;
      ++heights[aux];
      if(aux < Min)  Min = aux;
      if(aux > Max)  Max = aux;
   }
   int  high = Min + 17, max_low = Max - 17;
   if(Max < Min + 17)   ans = 0;
   else for(low = Min; low <= max_low; ++low, ++high){
      price = 0;
      for(int i = low - 1; i >= 0; --i)
         if(heights[i]) price += heights[i]*(low - i)*(low - i);
      for(int i = high + 1; i <= 100; ++i)
         if(heights[i]) price += heights[i]*(i - high)*(i - high);
      if(price < ans)   ans = price;

   }
   fout << ans << endl;

   return 0;
}
