#include <bits/stdc++.h>

using namespace std;
int main(){
   ios_base::sync_with_stdio(0);
   int cont = 0, n;
   //bool blank = 0;
   string input;
   while(getline(cin, input)){
      cont = n = 0;
      if(input == ".")  return 0;
      //if(blank)   cout << "\n";
      //else  blank = 1;
      string in[10010], sub[26];
      for(int i = 0; i < input.size(); ++i){
         if(input[i] == ' ') ++cont;
         else in[cont] += input[i];
      }

      int big = 0;
      map <string, int> s[26];
      for(int i = 0; i <= cont; ++i){
         if(s[(int)(in[i][0] - 'a')].count(in[i]))  s[(int)(in[i][0] - 'a')][in[i]] += (in[i].size() - 2);
         else if (in[i].size() > 2) s[(int)(in[i][0] - 'a')][in[i]] = in[i].size() - 2;
      }
      for(int i = 0; i < 26; ++i){
         big = 0;
         if(s[i].size()){
            ++n;
            for(map <string, int>::iterator it = s[i].begin(); it != s[i].end(); ++it)
               if((it -> second) > big){
                  big = (it -> second);
                  sub[i] = (it -> first);
               }
         }
      }
      for(int i = 0; i <= cont; ++i){
         if(in[i] == sub[(int)(in[i][0] - 'a')])  cout << in[i][0] << ".";
         else  cout << in[i];
         if(i != cont)  cout << " ";
      }
      cout << "\n" << n << "\n";

      for(int i = 0; i < 26; ++i)
         if(s[i].size())  cout << (char)(i + 'a') << ". = " << sub[i] << "\n";

   }


   return 0;
}
