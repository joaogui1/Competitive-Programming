/*
ID: joaogui1
LANG: C++
TASK: nuggets
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
int vals[13];
bool dp[66280];

int gcd(int a, int b){
   if(a < b)   swap(a, b);
   int aux;
   while(a%b){
      aux = b;
      b = a%b;
      a = b;
   }
   return b;
}

int main(){
   ios_base::sync_with_stdio(0);
   int n, g, aux;
   ifstream fin ("nuggets.in");
   ofstream fout ("nuggets.out");
   fin >> n;
   for(int i = 1; i <= n; ++i)   fin >> vals[i];
   //for(int i = 1; i <= n; ++i)   cout << vals[i] << endl;
   dp[0] = 1;
   for(int i = 1; i <= 65280; ++i)
      for(int j = 1; j <= n; ++j)
         if(i - vals[j] >= 0) dp[i] |= dp[i - vals[j]];
   //for(int i = 1; i <= 28; ++i)  cout << i << " " << dp[i] << endl;
   g = vals[1];
   for(int i = 2; i <= n; ++i)   g = gcd(g, vals[i]);
   if(g > 1 || n == 1)   fout << 0 << "\n";
   else  for(int i = 65280; i > 0; --i)
      if(!dp[i]){
         fout << i << "\n";
         break;
      }

   return 0;
}
