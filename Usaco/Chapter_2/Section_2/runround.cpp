/*
ID: joaogui1
LANG: C++
TASK: runround
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
#define entre(a, b, c) (a <= b && b <= c)
using namespace std;
bool is_run(int x){
   char num[15];
   int mark[15];
   memset(mark, 0, sizeof(mark));
   sprintf(num, "%d", x);
   int len, id = 0;
   len = strlen(num);
   for(int i = 0; i < len; ++i){
      id = (id + num[id] - '0')%len;
      ++mark[num[id] - '0'];
      if(mark[num[id] - '0'] != 1 || num[id] - '0' == 0) return false;
   }
   return true;
}
int main(){
   int n, aux;
   ifstream fin ("runround.in");
   ofstream fout ("runround.out");
   fin >> n;
   aux = n;
   while(1)
      if(is_run(n++) && n-1 != aux)   break;
   fout << n - 1 << endl;


   return 0;
}
