#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

pair <int, int> nums[510*510];
int main(){
   int t, n, aux;
   long long int ans;
   scanf("%d", &t);
   while(t--){
      ans = 0;
      memset(nums, 0, sizeof(nums));
      scanf("%d", &n);
      for(int i = 1; i <= n; ++i)
         for(int j = 1; j <= n; ++j){
            scanf("%d", &aux);
            nums[aux] = pair <int, int>(i, j);
         }
      for(int i = 2; i <= n*n; ++i)
         ans += abs(nums[i].first - nums[i - 1].first) + abs(nums[i].second - nums[i - 1].second);
      printf("%lld\n", ans);

   }



   return 0;
}
