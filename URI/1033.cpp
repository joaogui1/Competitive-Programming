#include <bits/stdc++.h>

using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   long long int cont = 0, n, b, mult[63][3][3];
   mult[0][0][0] = 1, mult[0][0][1] = 0, mult[0][0][2] = 1, mult[0][1][0] = 0, mult[0][1][1] = 0, mult[0][1][2] = 1, mult[0][2][0] = 0, mult[0][2][1] = 1, mult[0][2][2] = 1;
   while(cin >> n >> b){
      if(n + b < 1)  return 0;
      int vec[3] = {1, 1, 1}, temp[3] = {0};
      cout << "Case " << ++cont <<": ";
      for(int i = 1; i < 63; ++i){
         for(int j = 0; j < 3; ++j)
            for(int k = 0; k < 3; ++k)
               mult[i][j][k] = (mult[i - 1][j][0]*mult[i - 1][0][k] + mult[i - 1][j][1]*mult[i - 1][1][k] + mult[i - 1][j][2]*mult[i - 1][2][k])%b;
      }

      for(long long int i = 0; i < 63; ++i){

         if((1LL << i)&n)  for(int j = 0; j < 3; ++j) temp[j] = (vec[0]*mult[i][0][j] + vec[1]*mult[i][1][j] + vec[2]*mult[i][2][j])%b;
         if((1LL << i)&n)  for(int j = 0; j < 3; ++j) vec[j] = temp[j];
      }

      cout << n << " " << b << " " << vec[1] << endl;
   }

   return 0;
}
