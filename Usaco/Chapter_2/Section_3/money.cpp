/*
ID: joaogui1
LANG: C++
TASK: money
*/
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
long long int mark[10100], aux;
int main(){
   int n, v;
   ifstream fin ("money.in");
   ofstream fout ("money.out");
   fin >> v >> n;
   mark[0] = 1;
   for(int i = 0; i < v; ++i){
      fin >> aux;
      for(int j = 0; j <= n; ++j){
         if(j + aux > n)   break;
         if(mark[j]) mark[j + aux] += mark[j];
      }
   }
   fout << mark[n] << endl;

   return 0;
}
