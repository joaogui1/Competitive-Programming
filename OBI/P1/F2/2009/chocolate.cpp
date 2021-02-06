#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define SET(obj, a) memset(obj, a, sizeof(obj))
#define INF 0x3f3f3f3f
using namespace std;
int count[1<<20], move[1<<20];
int ans(int n, int m){
   for (int i = 0; i < n; ++i){
      if(count[i] == 0){ //se for impossivel vencer
         for(int j = 1; j <= m; ++j){
            ++count[i + j];
            move[i + j] = j;
         }
      }
      else if(count[i] == 1 && i + move[i] <= n){ //se so ha uma forma de vencer e se a nova pos vencedora importa
         ++count[i + move[i]]; //removendo move[i] tornamos i uma pos perdedora
         move[i + move[i]] = move[i];
      }
   }
   return count[n];
}

int main(){
   int n, m;
   scanf("%d %d", &n, &m);
   printf("%s\n",ans(n, m)?"Paula":"Carlos");
}
