#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
set <int> procs;
int depende[50010];
vector <int> pertence[50010];
vector <int> ans;
int main(){
   int n, m, a, b, davez;
   scanf("%d %d", &n, &m);
   for(int i = 0; i < m; ++i) {
      scanf("%d %d", &a, &b);
      ++depende[b];
      pertence[a].push_back(b);
   }
   for(int i = 0; i < n; ++i)
      sort(pertence[i].begin(), pertence[i].end());
   for (int i = 0; i < n; ++i)
      if(depende[i] == 0) procs.insert(i);
   while(!procs.empty()){
      davez = *procs.begin();procs.erase(procs.begin());
      ans.push_back(davez);
      for(int i = 0; i < pertence[davez].size(); ++i){
         --depende[pertence[davez][i]];
         if(depende[pertence[davez][i]] == 0)  procs.insert(pertence[davez][i]);
      }
   }
   if(ans.size() != n)  printf("*\n");
   else  for(int i = 0; i < ans.size(); ++i)
      printf("%d\n", ans[i]);
   return 0;
}
