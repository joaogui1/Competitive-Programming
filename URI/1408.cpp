#include <bits/stdc++.h>

using namespace std;

vector <int> war;

int main(){
   int n, l, aux, pos, ans;
   while(cin >> n >> l){
      if(n + l < 1)  return 0;
      war.clear();
      ans = 1 << 30;
      for(int i = 0; i < l; ++i){
         cin >> aux;
         war.push_back(aux);
      }
      for(int i = 0; i < l; ++i){
         pos = (upper_bound(war.begin(), war.end(), war[i] + n - 1) - war.begin());
         --pos;
         ans = min(ans, war[pos] - war[i] - pos + i + (war[i] + n - 1 - war[pos]) );
      }
      cout << ans << endl;
   }

   return 0;
}
