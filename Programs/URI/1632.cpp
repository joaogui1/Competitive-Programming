#include <bits/stdc++.h>

using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   int n, ans;
   string input;
   cin >> n;
   while(n--){
      ans = 1;
      cin >> input;
      for(int i = 0; i < input.size(); ++i){
         if(input[i] == 'a' || input[i] == 'A' || input[i] == 'e' || input[i] == 'E' || input[i] == 'i' || input[i] == 'I' || input[i] == 'o' || input[i] == 'O' || input[i] == 's' || input[i] == 'S')
            ans *= 3;
         else
            ans *= 2;
      }
      cout << ans << "\n";
   }


   return 0;
}
