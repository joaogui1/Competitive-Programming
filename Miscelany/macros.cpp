#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#define max(a, b) a > b ? a:b
#define swap(a,b) int aux = a; a = b; b = aux
#define print(a, b) int p = 0; do{cout << a[p++] << endl;}while(b >= p)
#define F0(n) for(int i = 0; i < n; ++i)
#define F1(n) for(int i = 1; i <= n; ++i)
using namespace std;
auto ss(auto a, auto b){
   return a+b;
}
int main(){
   int a, b, c, d[] =  {0,1,2,3};
   string aux1, aux2;
   aux1 = "aaaa";
   aux2 = "bbbb";
   a = 3;
   b = 4;
   c = max(a,b);
   cout << c << endl;
   cout << a << " " << b << endl;
   swap(a, b);
   cout << a << " " << b << endl;
   print(d, b);
   F0(a) cout << i << endl;
   F1(a) cout << i << endl;
   auto k = a + b;
   cout << k << endl;
   cout << ss(3.5, 4.1) << endl;
   cout << ss(a,b) << endl;
   cout << aux1 << " " << aux2  << " " << ss(aux1, aux2) << endl;
   return 0;
}
