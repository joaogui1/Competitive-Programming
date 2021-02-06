/*
ID: joaogui1
LANG: C++
TASK: humble
*/
#include <set>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

long long int p[110];
set <long long int> s;

int main(){
   int n, k;
   long long int ans = 0, aux, t;
   ifstream fin ("humble.in");
   ofstream fout ("humble.out");
   fin >> k >> n;

   for(int i = 0; i < k; ++i){
         fin >> p[i];
         s.insert(p[i]);
   }

   for(int i = 0; i < k; ++i){

      set<long long int>::iterator it = s.begin();
      while(1){
         aux = (*it)*p[i];
         //cout << aux << endl;
         if(aux < 0) break;
         if(s.size() > n){
            s.erase(--s.end());
            if(aux > *(--s.end()))  break;
         }
         s.insert(aux);
         ++it;
      }
   }
   fout << *(--s.end()) << endl;
   return 0;
}
