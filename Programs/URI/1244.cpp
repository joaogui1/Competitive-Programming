#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(string a, string b){
   return a.size() > b.size();
}

int main(){
   ios_base::sync_with_stdio(0);
   string input, s[60];
   int t, beg, cont;
   char a;
   cin >> t;
   getline(cin, input);
   while(t--){
      cont = beg = 0;
      getline(cin, input);
      for(int i = 0; i < input.size(); ++i){
         if(input[i] == ' '){
            s[cont++] = input.substr(beg, i - beg);
            beg = i + 1;
         }
      }
      s[cont++] = input.substr(beg, input.size() - beg);
      stable_sort(s, s + cont, comp);
      for(int i = 0; i < cont - 1; ++i) cout << s[i] << " ";
      cout << s[cont - 1];
      cout << "\n";
   }



   return 0;
}
