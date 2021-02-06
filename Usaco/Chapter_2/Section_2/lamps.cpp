/*
ID: joaogui1
LANG: C++
TASK: lamps
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
#define entre(a, b, c) (a <= b && b <= c)
using namespace std;
int lamps[32][110], final[110], n;
void trans_0(int a){
   for(int i = 1; i <= n; ++i)
      lamps[a][i] = 1;
   return;
}
void trans_1(int a){
   for(int i = 1; i <= n; ++i)
      lamps[a][i] = abs(lamps[a][i] - 1);
   return;
}
void trans_2(int a){
   for(int i = 1; i <= n; i+=2)
      lamps[a][i] = abs(lamps[a][i] - 1);
   return;
}
void trans_3(int a){
   for(int i = 2; i <= n; i+=2)
      lamps[a][i] = abs(lamps[a][i] - 1);
   return;
}
void trans_4(int a){
   for(int i = 1; i <= n; i+=3)
      lamps[a][i] = abs(lamps[a][i] - 1);
   return;
}
bool check(int a){
   for(int i = 1; i <= n; ++i)
      if(final[i] != -1 && final[i] != lamps[a][i])   return 0;
   return 1;
}
int main(){
   int c, aux, imp = 1;
   ifstream fin ("lamps.in");
   ofstream cout ("lamps.out");
   memset(final, -1, sizeof(final));
   fin >> n >> c;
   while(1){
      fin >> aux;
      if(aux == -1)  break;
      final[aux] = 1;
   }
   while(1){
      fin >> aux;
      if(aux == -1)  break;
      final[aux] = 0;
   }
   for(int i = 0; i <= 15; ++i){
      trans_0(i);
      if(i & 1)   trans_1(i);
      if(i & 2)   trans_2(i);
      if(i & 4)   trans_3(i);
      if(i & 8)   trans_4(i);
   }
   //for(int i = 1; i < n; ++i) cout << lamps[8][i];
   //cout << lamps[8][n] <<endl;
   //for(int i = 1; i < n; ++i) cout << final[i];
   //cout << final[n] <<endl;
   if(c == 0){
      if(check(0)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[0][i];
         cout << lamps[0][n] <<endl;
      }
   }
   else  if(c == 1){
         if(check(1)){
            imp = 0;
            for(int i = 1; i < n; ++i) cout << lamps[1][i];
            cout << lamps[1][n] <<endl;
         }
         if(check(2)){
            imp = 0;
            for(int i = 1; i < n; ++i) cout << lamps[2][i];
            cout << lamps[2][n] <<endl;
         }
         if(check(8)){
            imp = 0;
            for(int i = 1; i < n; ++i) cout << lamps[8][i];
            cout << lamps[8][n] <<endl;
         }
         if(check(4)){
            imp = 0;
            for(int i = 1; i < n; ++i) cout << lamps[4][i];
            cout << lamps[4][n] <<endl;
         }
   }
   else if(c == 2){
      if(check(1)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[1][i];
         cout << lamps[1][n] <<endl;
      }
      if(check(12)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[12][i];
         cout << lamps[12][n] <<endl;
      }
      if(check(2)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[2][i];
         cout << lamps[2][n] <<endl;
      }
      if(check(9)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[9][i];
         cout << lamps[9][n] <<endl;
      }
      if(check(4)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[4][i];
         cout << lamps[4][n] <<endl;
      }
      if(check(10)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[10][i];
         cout << lamps[10][n] <<endl;
      }
      if(check(0)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[0][i];
         cout << lamps[0][n] <<endl;
      }
   }
   else{
      if(check(1)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[1][i];
         cout << lamps[1][n] <<endl;
      }
      if(check(12)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[12][i];
         cout << lamps[12][n] <<endl;
      }
      if(check(2)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[2][i];
         cout << lamps[2][n] <<endl;
      }
      if(check(8)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[8][i];
         cout << lamps[8][n] <<endl;
      }
      if(check(9)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[9][i];
         cout << lamps[9][n] <<endl;
      }
      if(check(4)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[4][i];
         cout << lamps[4][n] <<endl;
      }
      if(check(10)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[10][i];
         cout << lamps[10][n] <<endl;
      }
      if(check(0)){
         imp = 0;
         for(int i = 1; i < n; ++i) cout << lamps[0][i];
         cout << lamps[0][n] <<endl;
      }
   }
   if(imp)  cout <<  "IMPOSSIBLE" << endl;
   return 0;
}
