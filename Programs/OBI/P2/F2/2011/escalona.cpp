#include <set>
#include <cstdio>
#include <vector>

using namespace std;

int depende[50100];
vector <int> filhos[50100], ans;
set <int> procs;
int main(){
   int n, m, a, b, cont = 0, davez;
   scanf("%d %d", &n, &m);
   for(int i = 0; i < m; ++i){
      scanf("%d %d", &a, &b);
      filhos[a].push_back(b);
      ++depende[b];
   }
   for(int i = 0; i < n; ++i)
      if(depende[i] == 0)
         procs.insert(i);

   while(!procs.empty()){
      ++cont;
      davez = *procs.begin();
      procs.erase(davez);
      ans.push_back(davez);
      for(int i = 0; i < filhos[davez].size(); ++i)
         if(--depende[filhos[davez][i]] == 0)   procs.insert(filhos[davez][i]);
   }
   if(cont != n)  printf("*\n");
   else  for(int i = 0; i < ans.size(); ++i) printf("%d\n", ans[i]);
   return 0;
}
