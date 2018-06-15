#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
   int f[3], sum = 0;
   scanf("%d %d %d", &f[0], &f[1], &f[2]);
   sort(f, f + 3);
   sum += f[0];
   sum += max(0, f[1] - f[0] - 200);
   sum += max(0, f[2] - f[1] - 200);
   sum += max(0, 600 - f[2] - 200);
   printf("%d\n", 100*sum);

   return 0;
}
