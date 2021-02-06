#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;
int dp[1010][1010][2];
string A[1010], B[1010];

int main(){
   ios_base::sync_with_stdio(0);
   int n;
   string a, b;
   while(1){
      cin >> n;
      if(n == 0)  break;
      cin >> a >> b;
      memset(dp, -1, sizeof(dp));

      for(int i = 0; i < int(a.size()) - n + 1; ++i) A[i] = a.substr(i, n);
      for(int i = 0; i < int(b.size()) - n + 1; ++i) B[i] = b.substr(i, n);

      
   }




   return 0;
}
