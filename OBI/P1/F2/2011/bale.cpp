#include <cstdio>
#define maxbit 100010
int bit[maxbit];
void update(int x, int val){
   while(x < maxbit){
      bit[x] += val;
      x += x&(-x);
   }
   return;
}
int sum(int x){
   int ret = 0;
   while(x > 0){
      ret += bit[x];
      x -= x&(-x);
   }
   return ret;
}
int main(){
   int n, aux, ans = 0;
   scanf("%d", &n);
   while(n--){
      scanf("%d", &aux);
      update(aux,1);
      ans += sum(maxbit) - sum(aux);
   }
   printf("%d\n", ans);

   return 0;
}
