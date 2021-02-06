/*
ID: joaogui1
LANG: C++
TASK: preface
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
int I[3600], V[3600], X[3600], L[3600], C[3600], D[3600], M[3600];
int to_roman_i(int x){
   //cout << x << endl;
   if(I[x] != -1) return I[x];
   if(entre(1, x, 3))   return I[x] = x;
   if(entre(4, x, 8))   return I[x] = to_roman_i(abs(x - 5));
   return I[x] = to_roman_i(abs(x - 10));
}
int to_roman_v(int x){
   if(V[x] != -1) return V[x];
   if(entre(1, x, 3))   return V[x] = 0;
   if(entre(4, x, 8))   return V[x] = 1;
   return V[x] = to_roman_v(abs(x - 10));
}
int to_roman_x(int x){
   if(X[x] != -1) return X[x];
   if(entre(1, x, 8))   return X[x] = 0;
   if(entre(9, x, 39))  return X[x] = 1 + to_roman_x(abs(x - 10));
   if(entre(40, x, 49))  return X[x] = 1 + to_roman_x(abs(x - 40));
   return X[x] = to_roman_x(abs(x - 50));
}
int to_roman_l(int x){
   if(L[x] != -1) return L[x];
   if(entre(1, x, 39))  return L[x] = 0;
   if(entre(40, x, 89)) return L[x] = 1;
   return L[x] = to_roman_l(abs(x - 100));
}
int to_roman_c(int x){
   if(C[x] != -1) return C[x];
   if(entre(1, x, 89))  return C[x] = 0;
   if(entre(90, x ,399))   return C[x] = 1 + to_roman_c(abs(x - 100));
   if(entre(400, x, 499))  return C[x] = 1 + to_roman_c(abs(x - 400));
   return C[x] = to_roman_c(abs(x - 500));
}
int to_roman_d(int x){
   if(D[x] != -1) return D[x];
   if(entre(1, x, 399))  return D[x] = 0;
   if(entre(400, x, 899)) return D[x] = 1;
   return D[x] = to_roman_d(abs(x - 1000));
}
int to_roman_m(int x){
   if(M[x] != -1) return M[x];
   if(entre(1, x, 899))  return M[x] = 0;
   return M[x] = 1 + to_roman_m(abs(x - 1000));
}
int main(){
   int n, i = 0, v = 0, x = 0, l = 0, c = 0, d = 0, m = 0;
   ifstream fin ("preface.in");
   ofstream cout ("preface.out");
   fin >> n;
   memset(I, -1, sizeof(I));memset(V, -1, sizeof(V));memset(X, -1, sizeof(X));memset(L, -1, sizeof(L));memset(C, -1, sizeof(C));memset(D, -1, sizeof(D));memset(M, -1, sizeof(M));
   I[0] = V[0] = X[0] = L[0] = C[0] = D[0] = M[0] = 0;
   for(int j = 1; j <= n; ++j){
      to_roman_i(j);
      to_roman_v(j);
      to_roman_x(j);
      to_roman_l(j);
      to_roman_c(j);
      to_roman_d(j);
      to_roman_m(j);
   }
   for(int j = 1; j <= n; ++j)   i += I[j];
   cout << "I " << i << endl;
   if(n >= 4){
      for(int j = 1; j <= n; ++j)   v += V[j];
      cout << "V " << v << endl;
   }
   if(n >= 9){
      for(int j = 1; j <= n; ++j)   x += X[j];
      cout << "X " << x << endl;
   }
   if(n >= 40){
      for(int j = 1; j <= n; ++j)   l += L[j];
      cout << "L " << l << endl;
   }
   if(n >= 90){
      for(int j = 1; j <= n; ++j)   c += C[j];
      cout << "C " << c << endl;
   }
   if(n >= 400){
      for(int j = 1; j <= n; ++j)   d += D[j];
      cout << "D " << d << endl;
   }
   if(n >= 900){
      for(int j = 1; j <= n; ++j)   m += M[j];
      cout << "M " << m << endl;
   }
   return 0;
}
