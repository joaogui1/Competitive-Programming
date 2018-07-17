#include <stack>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

bool Open(char a){
   return a == '(' || a == '[' || a == '{';
}

char eq(char a){
   switch (a) {
      case '(':
         return ')';
      case '[':
         return ']';
      case  '{':
         return '}';
   }
}

int main(){
   int parens = 0, brackets = 0, braces = 0, n, sz;
   bool vdc;
   string inp;
   scanf("%d", &n);
   while(n--){
      cin >> inp;
      sz = inp.size();
      stack <char> s;
      vdc = 1;
      for(int i = 0; i < sz && vdc; ++i){
         if(Open(inp[i]))  s.push(inp[i]);
         else{
            if(s.empty() || eq(s.top()) != inp[i]) vdc = 0;
            else
               s.pop();
         }
      }
      if(!s.empty()) vdc = 0;
      printf("%s\n", (vdc)?"S":"N");
   }

   return 0;
}
