/*
ID: joaogui1
LANG: C++
TASK: buylow
*/
#include <set>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#define MAXN 5010

using namespace std;

ifstream fin ("buylow.in");
ofstream fout ("buylow.out");

struct bigint{
   int len;
   vector <int> d;
   bigint(int q = 0): len(q), d(500, 0) {}
};

bigint add(bigint a, bigint b){
   bigint c = bigint();
   int carry = 0;
   for(int i = 0; i < max(a.len, b.len); ++i){
      c.d[i] = a.d[i] + b.d[i] + carry;
      carry = c.d[i]/10;
      c.d[i] %= 10;
   }
   if(carry != 0){
      c.d[max(a.len, b.len)] = carry;
      c.len = max(a.len, b.len) + 1;
      return c;
   }
   c.len = max(a.len, b.len);
   return c;
}

void print(bigint a){
   for(int i = a.len - 1; i != -1; --i) fout << a.d[i];
   fout << "\n";
}

int input[MAXN], dp[MAXN];
bigint dpnums[MAXN];
int main(){
   ios_base::sync_with_stdio(0);
   int n, maxlen;
   bigint num_sols = bigint(1);
   long long int aux;
   fin >> n;
   if(n == 1){
      fout << "1 1\n";
      return 0;
   }

   for(int i = 0; i != n; ++i) fin >> input[i];

   for(int i = 0; i < n; ++i){
      dp[i] = 1;
      dpnums[i] = bigint(1);
      dpnums[i].d[0] = 1;
   }
   //for(int i = 0; i < n; ++i) print(dpnums[i]);

   set <int> final;
   for(int i = n - 1; i != -1; --i){
      int _max = 0;
      bigint maxnum = bigint(1);
      maxnum.d[0] = 1;
      for(int j = i + 1; j < n; ++j){
         if(input[j] >= input[i])   continue;
         if(dp[j] > _max){
            _max = dp[j];
            maxnum = dpnums[j];
            final.erase(final.begin(), final.end());
            final.insert(input[j]);
         }
         else if(dp[j] == _max && !final.count(input[j])){
            maxnum = add(maxnum, dpnums[j]);
            final.insert(input[j]);
         }
      }
      dp[i] = _max + 1;
      dpnums[i] = maxnum;
      //print(dpnums[i]);
   }

   maxlen = 0;
   num_sols.d[0] = 1;
   for(int i = 0; i < n; ++i){
      //cout << num_sols.d[0] << endl;

      if(dp[i] > maxlen){
         maxlen = dp[i];
         num_sols = dpnums[i];
         final.erase(final.begin(), final.end());
         final.insert(input[i]);
      }
      else if(dp[i] == maxlen && !final.count(input[i])){
         num_sols = add(num_sols, dpnums[i]);
         final.insert(input[i]);
      }
   }
   fout << maxlen << " ";
   print(num_sols);
   return 0;
}
