#include <cstdio>
int G[210][210], n, m, k, a, b, dx[3] = {-1, 0, 1}, dy[3] = {-1, 0, 1}, ans = 0;
bool limits(int x, int y){
   return (x <= n && x > 0 && y <= m && y > 0);
}
void flood(int x, int y){
   for(int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
         if(limits(x + dx[i], y + dy[j])&& G[x + dx[i]][y + dy[j]] == 0){
            ++G[x + dx[i]][y + dy[j]];
            flood(x + dx[i], y + dy[j]);
            ++ans;
         }
      return;
}
int main(){
   int x, y;
   scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
   for(int i = 0; i < k; ++i){
      scanf("%d %d", &a, &b);
      G[a][b] = -1;
   }
   flood(x, y);
   printf("%d\n", ans);
   return 0;
}
