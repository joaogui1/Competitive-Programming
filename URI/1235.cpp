#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   int t;
   cin >> t;
   string input;
   getline(cin, input);
   while(t--){
      getline(cin, input);
      if(!(input.size() & 1)){
         for(int i = 0; i < input.size()/4; ++i){
            swap(input[i], input[input.size()/2 - i - 1]);
            swap(input[i + input.size()/2], input[input.size() - i - 1]);
         }
      }
      else{
         for(int i = 0; i < input.size()/4; ++i){
            swap(input[i], input[input.size()/2 - i - 1]);
            swap(input[i + input.size()/2 + 1], input[input.size() - i - 1]);
         }
      }
      cout << input << "\n";
   }


   return 0;
}
