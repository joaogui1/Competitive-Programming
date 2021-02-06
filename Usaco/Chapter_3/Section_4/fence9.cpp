/*
ID: joaogui1
LANG: C++
TASK: fence9
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
   if(a < b)   swap(a, b);
   if(b == 0)  return a;
   int aux;
   while(a%b){
      aux = b;
      b = a%b;
      a = aux;
   }
   return b;
}

int main(){
   ios_base::sync_with_stdio(0);
   int m, n, p, b = 0, i = 0, a, aux, auy;
   ifstream fin ("fence9.in");
   ofstream fout ("fence9.out");
   fin >> n >> m >> p;
   b += p;
   b += gcd(n, m);
   b += gcd(abs(n - p), m);

   a = m*p;
   //fout << b << " " << a << " " << endl;
   i = a + 2 - b;
   fout << i/2 << "\n";

   return 0;
}
