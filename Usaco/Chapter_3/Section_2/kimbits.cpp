/*
ID: joaogui1
LANG: C++
TASK: kimbits
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
long long int bin[40][40];
string ans;
void initialize(){
   for(int i = 0; i < 40; ++i)   bin[i][0] = bin[0][i] = 1;
   for(int i = 1; i < 40; ++i)
      for(int j = 1; j < 40; ++j)
         bin[i][j] = bin[i - 1][j] + bin[i - 1][j - 1];
   //for(int i = 1; i < 40; ++i)
      //for(int j = 1; j < 40; ++j)
         //bin[i][j] += bin[i][j - 1];
   return;
}
void f(int N, long long int I, int l){
   for(int i = 0; i < N; i++){
        int len = N - i, c = bin[len - 1][l];
        if(c < I){
            ans[i] = '1';
            l--;
            I -= c;
        }
        else ans[i] = '0';
    }
   return;
}

int main(){
   int n, l;
   long long int I;
   char aux;
   ifstream fin ("kimbits.in");
   ofstream fout ("kimbits.out");
   fin >> n >> l >> I;
   for(int i = 0; i < n; ++i) ans += '0';
   initialize();
   //printf("ok\n");
   f(n, I, l);

   //cout << endl;
   fout << ans << endl;

}
