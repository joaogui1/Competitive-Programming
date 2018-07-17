/*
ID: joaogui1
LANG: C++
TASK: stamps
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int vals[3000000];
int stamp[60];

int main(){
   int n, k, ans;
   ifstream fin ("stamps.in");
   ofstream fout ("stamps.out");
   fin >> k >> n;
   for(int i = 0; i < n; ++i) fin >> stamp[i];
   //sort(stamp, stamp + n);
   for(ans = 1; vals[ans - 1] || ans == 1; ++ans){
      for(int j = 0; j < n; ++j){
         if(ans - stamp[j] > -1 && (vals[ans - stamp[j]] || ans - stamp[j] == 0) && vals[ans - stamp[j]] < k){
            if(ans - stamp[j] == 0) vals[ans] = 1;
            else if(vals[ans] == 0)  vals[ans] = vals[ans - stamp[j]] + 1;
            else  vals[ans] = min(vals[ans], vals[ans - stamp[j]] + 1);
         }
         //fout << ans << " " << vals[ans] << endl;
      }
   }
   ans -= 2;
   //for(int i = 1; i <= ans; ++i) fout << vals[i] << endl;
   fout << ans << endl;

   return 0;
}
