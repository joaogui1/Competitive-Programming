#include <cstdio>
//#include <utility>
//#include <algorithm>
//using namespace std;
int count[1001100], move[1001100];
int solve(int n, int m){
   for(int i = 0; i <= n; ++i){
      if(count[i] == 0){
         for(int j = 1; j <= m; ++j){
            ++count[i + j];
            move[i + j] = j;
         }
      }
      else if(count[i] == 1){
         ++count[i + move[i]];
         move[i + move[i]] = move[i];
      }
   }
   return count[n];
}
int main(){
   int n, m;
   scanf("%d %d", &n, &m);
   printf("%s\n",(solve(n, m) > 0)?"Paula":"Carlos");
   return 0;
}
