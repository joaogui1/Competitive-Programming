#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   bool vdc, feio;
   string input1;
   long long int ans, exp_;
   while(getline(cin, input1)){
      vdc = 1, feio = 0;
      string input2;
      for(int i = 0, cont = -1; i < input1.size(); ++i){
         if(input1[i] != ' ' && input1[i] != ',' && input1[i] != '0' && input1[i] != 'O' && input1[i] != 'o')   feio = 1;
         if(input1[i] != ' ' && input1[i] != ',' && feio){
              input2 += input1[i];
              ++cont;
         }
         if(cont > -1){
            if(input2[cont] == 'l') input2[cont] = '1';
            else if(input2[cont] == 'O' || input2[cont] == 'o')  input2[cont] = '0';
            else if('0' > input2[cont] || '9' < input2[cont])  vdc = 0;
         }
      }
      //cout << input2.size() << " " << vdc << endl;
      if(input2.size() == 0)  for(int i = 0; i < input1.size(); ++i) if(input1[i] == '0' || input1[i] == 'o' || input1[i] == 'O')   input2 += '0';
      if(input2.size() == 0 || !vdc || input2.size() > 10)  cout << "error\n";
      else{
         ans = 0LL;
         exp_ = 1;
         for(int i = input2.size() - 1; i >= 0; --i, exp_*=10)
            ans += exp_*(input2[i] - '0');
         if(ans > 2147483647) cout << "error\n";
         else  cout << ans << "\n";
      }

   }

   return 0;
}
