/*
ID: joaogui1
LANG: C++
TASK: hamming
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
int mark[1 << 9], n, b, d;
vector <int> ans;
int ham_dist(int a, int c){
   int ret = 0, x = (a ^ c);
   for(int i = 0; i < b; ++i){
      if(x & 1 << i) ++ret;
   }
   return ret;
}
int main(){
   int add;
   ifstream fin ("hamming.in");
   ofstream fout ("hamming.out");
   fin >> n >> b >> d;
   mark[0] = -1;
   ans.push_back(0);
   for(int j = 0; j < ans.size(); ++j){
      add = 1;
      if(ans.size() == n)  break;
      for(int i = 1; i < 1 << b; ++i)
         if(ham_dist(ans[j], i) >= d && mark[i] == j){
            ++mark[i];
            if(add){
               ans.push_back(i);
               add = 0;
               mark[i] = -1;
            }
         }
      }
   for(int j = 1; j <= ans.size() - 1; ++j){
      fout << ans[j-1];
      if(j % 10 == 0)   fout << endl;
      else  fout << " ";
   }
   fout << ans[ans.size() - 1] << endl;
   return 0;
}
