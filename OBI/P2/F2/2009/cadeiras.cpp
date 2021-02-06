#include <cstdio>
#include <vector>
#include <cstdlib>
#include <utility>
#include <algorithm>
using namespace std;
int G[210][210], pos[210][2];
vector <pair < pair <char, int> , int> > ans;
int main(){
   int l, c, comp;
   char dbg;
   bool vdc = 0;
   scanf("%d %d", &l, &c);
   for(int i = 1; i <= l; ++i)
      for(int j = 1; j <= c; ++j)
         scanf("%d", &G[j][i]);
   while(!vdc){
      //printf("ok\n");
      vdc = 1;
      for(int j = 1; j <= c; ++j){
         comp = (G[j][1] % c == 0)?c:G[j][1] % c;
         if( comp != j){
            ans.push_back(make_pair(make_pair('C', min(comp, j)), max(comp, j)));
            swap(G[j][1], G[comp][1]);
            vdc = 0;
         }
      }
   }
   vdc = 0;
   printf("%d\n", ans.size());
   while(!vdc){
      vdc = 1;
      for(int j = 1; j <= l; ++j){
         comp = (G[1][j] % c == 0)?(G[1][j]/c - 1):G[1][j]/c;
         ++comp;
         //scanf(" %c\n", &dbg);
         //printf("%d %d %d\n", G[1][j], j, comp);
         if( comp != j){
            ans.push_back(make_pair(make_pair('L', min(comp, j)), max(comp, j)));
            swap(G[1][j], G[1][comp]);
            vdc = 0;
         }
      }
   }
   printf("%d\n", int(ans.size()));
   for(int i = 0; i < ans.size(); ++i)
      printf("%c %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second);

   return 0;
}
