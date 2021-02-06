#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   int a, b, c;
   cin >> a >> b;
   if(a == b)  c = a;
   else  c = max(a, b);
   cout << c << "\n";

   return 0;
}
