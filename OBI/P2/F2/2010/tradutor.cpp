#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#define MOD 1000000007

using namespace std;

int n, un;
string a, b;

long long int ans[100100];
bool comp(int i, int k){
   if(i + 1 == un){
      for(int j = 0; j <= i; ++j){
         //cout << "j = " << j << " " << "k = " << k  << endl << a[j] << " "  << b[j + k] << " ";
         if(a[j] > b[j + k])  return 1;
         if(a[j] < b[j + k])  return 0;
      }
      cout << endl;
      return 1;
   }
   return un > i + 1;
}

long long int solve(int k){
   if(ans[k] != -1)  return ans[k];
   if(k == n)   return 1LL;
   long long int ret = 0;
   //string aux;
   for(int i = 0; i < n - k; ++i){
      //cout << "k = " << k << " i = " << i << endl;
      //aux += b[i + k];
      //if(b[i + k + 1] == '0')   continue;
      if(comp(i, k)){
         //cout <<  aux << "|";
         ret = (ret + solve(k + i + 1))%MOD;
      }
      else  break;
      //cout << endl;
   }
   return ans[k] = ret;
}
int main(){
   cin >> a >> b;
   n = b.size();
   un = a.size();
   memset(ans, -1, sizeof(ans));
   for(int i = 0; i < n; ++i)
      if(b[i] == '0')   ans[i]  = 0;
   //ans[n] = 0;
   printf("%lld\n", solve(0));

   return 0;
}
