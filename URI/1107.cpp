#include <bits/stdc++.h>

using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   int a, c, ant, at, sum;
   while(1){
      cin >> a >> c;
      sum = 0;
      if(a + c == 0) break;
      ant = a;
      for(int i = 0; i < c; ++i){
         cin >> at;
         sum += max(0, ant - at);
         ant = at;
      }
      cout << sum << "\n";
   }


   return 0;

}
