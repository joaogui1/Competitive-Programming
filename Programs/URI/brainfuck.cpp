#include <bits/stdc++.h>

using namespace std;

int p, in, ins;
string instr, input;
vector <char> mem;

int compile(int beg, int end){
   for(int ins = beg; ins < end; ++ins){
      cout << mem[p] << " " << p << " " << ins << " " << beg << endl;
      if(instr[ins] == '>')   ++p;
      else if(instr[ins] == '<')   --p;

      else if(instr[ins] == '+')   ++mem[p];
      else if(instr[ins] == '-')   cout << "help\n";//--mem[p];

      else if(instr[ins] == '.')   cout << mem[p];
      else if(instr[ins] == ',')   mem[p] = (in < input.size())?input[in++]:0;

      else if(instr[ins] == '['){

         if(mem[p] == 0 && ins == beg)
            return end;


         else if(mem[p] == 0){
            cout << "ok ";
            int ex = 0;
            for(int i = ins; i <= end; ++i){
               if(instr[i] == '[')   ++ex;
               if(instr[i] == ']')   --ex;

               if(ex == 0){
                  cout << i << endl << endl;
                  ins = i;
                  break;
               }
            }
            continue;
         }

         else if(ins != beg){
            int ex = 0;
            for(int i = ins; i <= end; ++i){
               if(instr[ins] == '[')   ++ex;
               if(instr[ins] == ']')   --ex;
               if(ex == 0){
                   compile(ins, i);
                   ins = i;
                   break;
               }
            }
         }
      }
      else if(instr[ins] == ']'){
         ins = beg;
         continue;
      }

      else if(instr[ins] == '#')   for(int i = 0; i < 10; ++i)   cout << mem[i];
   }
}

int main(){
   int n;
   cin >> n;
   for(int j = 1; j <= n; ++j){
      p = in = ins = 0;
      mem.assign(30000, 0);
      cout << "Instancia " << j << "\n";
      cin >> input >> instr;
      compile(0, instr.size());
   }



   return 0;
}
