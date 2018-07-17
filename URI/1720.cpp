#include <bits/stdc++.h>
#define pi 3.14159265358979323846

using namespace std;

int main(){
   cout.precision(0);
   cout.setf(ios::fixed);
   double ans = 1.0, n, m;
   while(cin >> n >> m){
      if(n + m < 1)  return 0;
      ans = 1.0;
      for(double i = 1; i <= ceil(m/2.0); ++i)
         for(double j = 1; j <= ceil(n/2.0); ++j)
            ans *= (4.0*cos((i*pi)/(m + 1.0))*cos((i*pi)/(m + 1.0)) + 4*cos((j*pi)/(n + 1.0))*cos((j*pi)/(n + 1.0)));
      cout << ans << endl;
   }

   return 0;
}
