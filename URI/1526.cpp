#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll modulo(ll a, ll b){
   if(a%b == 0)   return b;
   return a%b;
}

ll teto(ll a, ll b){
   if(a%b == 0)   return a/b;
   return a/b + 1;
}

int main(){
   ios_base::sync_with_stdio(0);
   ll li, c, d, step, pos, trips, costs;
   while(cin >> li >> d >> c){
      pos = 0;

      while(li > 0){
         if(li%c == 1)  --li;
         trips = teto(li, c);
         costs = 2*trips - 1;

         step = teto(modulo(li, c), costs);

         if(pos + step >= d){
            li -= (d - pos)*costs;
            break;
         }

         pos += step;
         li -= step*costs;

         if((li + costs)%c == 1)  ++li;
      }
      if(li > 0)  cout << li << "\n";
      else  cout << "impossivel\n";
   }


   return 0;
}
