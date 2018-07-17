#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int G[60][60], sum[10];
int main(){
   int n, wrongx = -1, wrongy = -1, test_sum, wrongval, rightval;
   scanf("%d", &n);
   for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
         scanf("%d", &G[j][i]);
   for(int i = 0; i < 3; ++i)
      for(int j = 0; j < n; ++j)
         sum[i + 1] += G[j][i];
   if(sum[1] == sum[2] && sum[1] == sum[3])  sum[0] = sum[1];
   else if(sum[1] == sum[2])  sum[0] = sum[1];
   else if(sum[3] == sum[2])  sum[0] = sum[2];
   else  sum[0] = sum[1];
   for(int i = 0; i < n; ++i){
      test_sum = 0;
      for(int j = 0; j < n; ++j)
         test_sum += G[j][i];
      if(test_sum != sum[0]){
         wrongy = i;
         break;
      }
   }
   for(int j = 0; j < n; ++j){
      test_sum = 0;
      for(int i = 0; i < n; ++i)
         test_sum += G[j][i];
      if(test_sum != sum[0]){
         wrongx = j;
         break;
      }
   }
   wrongval = G[wrongx][wrongy];
   rightval = wrongval + (sum[0] - test_sum);
   //cout << sum[0] << " " << sum[1] << " " << sum[2] << " " << sum[3] << endl;
   //cout << wrongx << " " << wrongy << " " << endl;
   printf("%d %d\n", rightval, wrongval);
   return 0;
}
