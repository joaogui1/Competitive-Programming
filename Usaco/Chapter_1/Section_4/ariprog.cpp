/*
ID: joaogui1
LANG: C++
TASK: ariprog
*/
#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
bool bisq[200000];
vector <pair <int, int> > ans;
int main(){
   int n, m, i;
   ifstream fin ("ariprog.in");
   ofstream fout ("ariprog.out");
   fin >> n >> m;
   for(int i = 0; i <= m; ++i)
      for(int j = 0; j <=m; ++j)
         bisq[i*i + j*j] = 1;
   for(int a = 0; a <= 2*m*m; ++a)
      if(bisq[a])
         for (int b = 1; b <= 2*m*m; ++b){
            if(a + (n - 1)*b > 2*m*m)  break;
            else  for(i = 1; i < n; ++i)
               if(!bisq[a + i*b])   break;
            if(i == n)  ans.push_back(make_pair(b,a));
         }
   if(ans.size() == 0) fout << "NONE" << endl;
   else{
      sort(ans.begin(), ans.end());
      int sz = ans.size();
      for(int i = 0; i < sz; ++i)   fout << ans[i].second << " " << ans[i].first << endl;
   }
   return 0;
}
