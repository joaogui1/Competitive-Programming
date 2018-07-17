#include <set>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   int t;
   bool vdc;
   string aux;
   cin >> t;
   getline(cin, aux);
   while(t--){
      set <char> s;
      vdc = 1;
      getline(cin, aux);
      for(int i = 0; i < aux.size(); ++i) s.insert(aux[i]);
      getline(cin, aux);
      for(int i = 0; i < aux.size() && vdc; ++i){
         if(s.count(aux[i]) == 1) s.erase(aux[i]);
         else{
            vdc = 0;
            cout << "CHEATER";
            break;
         }
      }
      getline(cin, aux);
      for(int i = 0; i < aux.size() && vdc; ++i){
         if(s.count(aux[i]) == 1) s.erase(aux[i]);
         else{
            vdc = 0;
            cout << "CHEATER";
            break;
         }
      }
      if(vdc)  for(set<char>::iterator it = s.begin(); it != s.end(); ++it)   cout << *it;
      cout << "\n";
   }


   return 0;

}
