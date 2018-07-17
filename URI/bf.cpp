#include <bits/stdc++.h>

using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   int n;
   string input, instr;
   cin >> n;
   for(int t = 1; t <= n; ++t){
      int p = 0, in = 0, loop = 0;
      stack <int> beg;
      int goes[30000] = {0};
      char _mem[30000] = {0};
      cout << "Instancia " << t << "\n";
      cin >> input >> instr;

      for(int i = 0; i < instr.size(); ++i){
         if(instr[i] == '[')  beg.push(i);
         if(instr[i] == ']'){
            goes[i] = beg.top();
            goes[beg.top()] = i;
            beg.pop();
         }
      }

      for(int ins = 0; ins < instr.size(); ++ins){
         //cout << ins << " " << instr[ins] << " " << _mem[p] << endl;
         if(instr[ins] == '>'){
            ++p;
            continue;
         }
         else if(instr[ins] == '<'){
            --p;
            continue;
         }
         else if(instr[ins] == '+')
            ++_mem[p];

         else if(instr[ins] == '-')
            --_mem[p];

         else if(instr[ins] == '.')
            cout << _mem[p];

         else if(instr[ins] == ',')
            _mem[p] = (in < input.size())?input[in++]:0;

         else if(instr[ins] == '#')
            for(int i = 0; i < 10; ++i)   cout << _mem[i];

         else if(instr[ins] == '['){
            ++loop;
            if(_mem[p] == 0){
               ins = goes[ins];
               --loop;
               continue;
            }
         }
         else if(instr[ins] == ']'){
            //cout << "ok\n";
            --loop;
            ins = goes[ins] - 1;
            continue;
         }
         if(_mem[p] == 0 && loop <= 0)
            break;

         //cout << "ok\n";
      }

      cout << "\n" << "\n";

   }

   return 0;
}
