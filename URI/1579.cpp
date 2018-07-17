#include <bits/stdc++.h>

using namespace std;

vector <int> p;

bool vdc(int lim, int c){
   int sum[15] = {0}, cont = 1;
   for(int i = 0; i < p.size(); ++i){
      if(sum[cont] + p[i] > lim) sum[++cont] += p[i];
      else  sum[cont] += p[i];
      if(cont > c)   break;
   }
   return (cont <= c);
}

int main(){
   ios_base::sync_with_stdio(0);
   int N, n, c, f, aux, beg, end, med;
   bool val;
   cin >> N;
   while(N--){
      cin >> n >> c >> f;
      p.clear();
      beg = end = 0;
      for(int i = 0; i < n; ++i){
          cin >> aux;
          p.push_back(aux);
          beg = max(beg, aux);
          end += aux;
      }

      while(end - beg > 1){
         med = (end + beg)/2;
         val = vdc(med, c);
         if(val && !vdc(med - 1, c)) break;
         else if(val)   end = med;
         else  beg = med;
      }
      if(vdc(med, c) && vdc(med - 1, c))  --med;
      if(!vdc(med, c))  ++med;
      cout << med << " $" << f*med*c << "\n";

   }


   return 0;
}
