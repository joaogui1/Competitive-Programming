/*
ID: joaogui1
LANG: C++
TASK: pprime
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#define max(a,b) a > b ? a : b
int primes[1000000];
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
   for(i = 0;primes[i]!=0 && primes[i]*primes[i] <= x; ++i){
      if(x%primes[i] == 0 && x != primes[i]) return 0;
      else if(x == primes[i]) return 1;
   }
   return 1;
}
int main(){
   int a, b, p = 1, num;
   FILE *fin  = fopen ("pprime.in", "r");
   FILE *fout = fopen ("pprime.out", "w");
   fscanf(fin,"%d %d", &a, &b);
   initialize(b);
   int i = 0;
   //while(primes[i] != 0)   cout << primes[i++] << endl;
   if(a < 10)  for(int d1 = a; d1 <= 9; ++d1) if(is_prime(d1))  fprintf(fout, "%d\n", d1);
   if(a <= 11 && b >= 11)   fprintf(fout, "11\n", num);
   if(a <= 999)
      for(int d1 = 1; d1 <= 9; ++d1)
         for(int d2 = 0; d2 <= 9; ++d2){
            num = 100*d1 + 10*d2 + d1;
            if(is_prime(num) && a <= num && num <= b) fprintf(fout, "%d\n", num);
            else if(100*d1 + 10*d2 + d1 > b)   break;
         }
   if(a <= 9999)
      for(int d1 = 1; d1 <= 9; ++d1)
         for(int d2 = 0; d2 <= 9; ++d2){
            num = 1000*d1 + 100*d2 + 10*d2 + d1;
            if(is_prime(num) && a <= num && num <= b) fprintf(fout, "%d\n", num);
            else if(num > b)   break;
         }
   if(a <= 99999)
   for(int d1 = 1; d1 <= 9; ++d1)
      for(int d2 = 0; d2 <= 9; ++d2)
         for(int d3 = 0; d3 <= 9; ++d3){
            num = 10000*d1 + 1000*d2 + 100*d3 + 10*d2 + d1;
            if(is_prime(num) && a <= num && num <= b) fprintf(fout, "%d\n", num);
            else if(num > b)   break;
      }
   if(a <= 999999)
      for(int d1 = 1; d1 <= 9; ++d1)
         for(int d2 = 0; d2 <= 9; ++d2)
            for(int d3 = 0; d3 <= 9; ++d3){
               num = 100000*d1 + 10000*d2 + 1000*d3 + 100*d3 + 10*d2 + d1;
               if(is_prime(num) && a <= num && num <= b) fprintf(fout, "%d\n", num);
               else if(num > b)   break;
            }
   if(a <= 9999999)
      for(int d1 = 1; d1 <= 9; ++d1)
         for(int d2 = 0; d2 <= 9; ++d2)
            for(int d3 = 0; d3 <= 9; ++d3)
               for(int d4 = 0; d4 <= 9; ++d4){
               num = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;
               if(is_prime(num) && a <= num && num <= b) fprintf(fout, "%d\n", num);
               else if(num > b)   break;
               }

   return 0;
}
