#include <bits/stdc++.h>

using namespace std;

long long int find_cycle(int n){
   long long int fib[3] = {1, 1, 2}, ret = 1;
   while(++ret){
      fib[2] = (fib[0] + fib[1])%n;
      if(fib[2] == fib[1] && fib[1] == 1) return ret;
      fib[0] = fib[1];
      fib[1] = fib[2];
   }
}

long long int find_fib(int n, int c){
   long long int fib[34][2][2], vec[2] = {0, 1}, temp[2];
   fib[0][0][0] = 0, fib[0][1][0] = fib[0][0][1] = fib[0][1][1] = 1;
   for(int i = 1; i < 31; ++i)
      for(int j = 0; j < 2; ++j)
         for(int k = 0; k < 2; ++k)
            fib[i][j][k] = (fib[i - 1][j][0]*fib[i - 1][0][k] + fib[i - 1][j][1]*fib[i - 1][1][k])%c;

   for(int i = 0; i < 31; ++i)
      if((1 << i)&n){
         for(int j = 0; j < 2; ++j) temp[j] = (vec[0]*fib[i][0][j] + vec[1]*fib[i][1][j])%c;
         for(int j = 0; j < 2; ++j) vec[j] = temp[j];
      }
   return vec[0];
}

int main(){
   ios_base::sync_with_stdio(0);
   long long int c, n, m;
   while(cin >> n >> m){
      c = find_cycle(m);
      --c;
      n = (find_fib(n, c))%c;
      n = (find_fib(n, m))%m;
      cout << n << endl;
   }
