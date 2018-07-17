/*
ID: joaogui1
LANG: C++
TASK: sort3
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
#define min(a, b) a<b ? a:b
using namespace std;
int nums[1100], vals[10];
int main(){
   int n, aux, ans = 0, j;
   ifstream fin ("sort3.in");
   ofstream fout ("sort3.out");
   fin >> n;
   for(int i = 0; i < n; ++i){
      fin >> nums[i];
      ++vals[nums[i]];
   }
   for(int i = vals[1]; i < n; ++i){
      if(nums[i] == 1){
         for(j = 0; j < vals[1]; ++j){
            if(nums[j] == 2){
               aux = j;
               break;
            }
            else if(nums[j] == 3)   aux = j;
         }
         nums[i] = nums[aux];
         nums[aux] = 1;
         ++ans;
      }
   }
   for(int i = vals[1] + vals[2]; i < n; ++i)
      if(nums[i] == 2)  ++ans;
   fout << ans << endl;
   return 0;
}
