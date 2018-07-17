#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   bool m;
   string input;
   while(getline(cin, input)){
      m = 1;
      for(int i = 0; i < input.size(); ++i){
         if(input[i] == ' ')  cout << input[i];
         else{
            if(input[i] < 'a' && m) cout << input[i];
            else if(input[i] < 'a' && !m) cout << char(input[i] + 32);
            else if(m)  cout << char(input[i] - 32);
            else  cout << input[i];
            m ^= 1;
         }
      }
      cout << "\n";
   }


   return 0;
}
