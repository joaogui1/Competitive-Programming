#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
   int t;
   double h, n, m, ans, hei;
   scanf("%d", &t);
   while(t--){
      scanf("%lf %lf %lf", &h, &n, &m);
      hei = ans = 0.0;
      while(hei < h){
         if(hei + n >= h){
            //cout << h << " " << hei << endl;
            ans += (h - hei)/n;
            break;
         }
         hei += n;
         hei -= m;
         ans += 1.0;
         //cout << hei << endl;
      }
      printf("%0.2lf\n", ans);
   }

   return 0;
}
