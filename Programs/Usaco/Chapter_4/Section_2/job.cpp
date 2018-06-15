/*
ID: joaogui1
LANG: C++
TASK: job
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
vector <int > a, b;
int main(){
   ios_base::sync_with_stdio(0);
   int n, na, nb, at, bt, aux, ans;
   bool end;
   ifstream fin ("job.in");
   ofstream fout ("job.out");
   fin >> n >> na >> nb;
   for(int i = 1; i <= na; ++i){
      fin >> aux;
      a.push_back(aux);
   }
   for(int i = 1; i <= nb; ++i){
      fin >> aux;
      b.push_back(aux);
   }
   at = 0;
   vector <int> afinish(na, 0), atask(n, 0);

   for(int j = 0; j < n; ++j){
      int min_finish = 1 << 28, index = -1;
      for(int i = 0; i < na; ++i)
         if(afinish[i] + a[i] < min_finish){
            min_finish = afinish[i] + a[i];
            index = i;
         }

      afinish[index] += a[index];
      at = afinish[index];
      atask[j] = min_finish;
   }

   bt = 0;
   vector <int> bfinish(nb, 0), btask(n, 0);

   for(int j = n - 1; j > -1; --j){
      int min_finish = 1 << 28, index = -1;
      for(int i = 0; i < nb; ++i)
         if(bfinish[i] + b[i] < min_finish){
            min_finish = bfinish[i] + b[i];
            index = i;
         }

      bfinish[index] += b[index];
      btask[j] = min_finish;
   }

   ans = 0;
   for(int i = 0; i < n; ++i) if(atask[i] + btask[i] > ans) ans = atask[i] + btask[i];

   fout << at << " " << ans << "\n";
   return 0;
}
