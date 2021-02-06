#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
int main(){
   ios_base::sync_with_stdio(0);
   int t, m;
   double val1, val2, p;
   cin >> t;
   while(t--){
      cin >> m >> p;
      val1 = 1000000000.0*(1 - pow(-p, m))/(p + 1);
      val2 = 1000000000.0 - val1;
       cout.precision(10);
      cout << fixed << val1 << " " << val2 << "\n";
   }

   return 0;
}
