/*
ID: joaogui1
LANG: C++
TASK: fact4
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   long long int ans = 1LL, n;
   ifstream fin ("fact4.in");
   ofstream fout ("fact4.out");
   fin >> n;
   for(long long int i = 1LL; i <= n; ++i){
      ans*=i;
      while(ans%10LL == 0LL){
            //printf("%lld  ans\n", ans);
            ans/=10LL;
      }
      ans %= 1000000000LL;
   }
   fout << ans%10LL << endl;

   return 0;
}
