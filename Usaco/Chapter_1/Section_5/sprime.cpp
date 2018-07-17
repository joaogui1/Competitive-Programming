/*
ID: joaogui1
LANG: C++
TASK: sprime
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
#define max(a,b) a > b ? a : b
int primes[1000000];
vector <int> ans;
void initialize(int x){
   int cont = 0;
   primes[cont++] = 2;
   for(int i = 3; i*i <= x; ++i){
      for(int j = 0; j < cont; ++j){
         if(i%primes[j] == 0)  break;
         if(j == cont - 1) primes[cont++] = i;
      }
   }
}
bool is_prime(int x){
   int i;
   if(x == 1)  return 0;
   for(i = 0;primes[i]!=0 && primes[i]*primes[i] <= x; ++i){
      if(x%primes[i] == 0 && x != primes[i]) return 0;
      else if(x == primes[i]) return 1;
   }
   return 1;
}
void sprime(int d, int n, int lim){
   if(is_prime(d)){
      if(n == lim)
         ans.push_back(d);
      else for(int i = 1; i < 10; ++i)    sprime(10*d + i, n + 1, lim);
   }
   return;
}
int main(){
   int n, aux = 10;
   ifstream fin("sprime.in");
   ofstream fout("sprime.out");
   fin >> n;
   for(int i = 0; i < n; ++i) aux*=10;
   initialize(aux);
   sprime(0, 0, n);
   for(int i = 0; i < ans.size(); ++i) fout << ans[i] << endl;
   return 0;
}
