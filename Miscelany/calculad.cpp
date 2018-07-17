#include <stack>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

bool _alpha(char a){
   return ('a' <= a <= 'z');
}

double var[30];

double solve(string a){
   char helper;
   stack <char> op;
   stack <double> nums;
   for(int i = 0; i < int(a.size()); ++i){
      if(a[i] == '('){
         for(int j = i + 1; j < int(a.size()); ++j)
            if(a[j] = ')') nums.push(solve(aux.substr(i+1, j - i)))
      }

      else  if(_alpha(a[i]))  nums.push(var[a[i] - 'a']);

      else  if(a[i] == '-' || a[i] == '+')   op.push(a[i]);
      else{
         helper = nums.top();nums.pop();
         if(a[i] == '*' && a)
      }
   }

}

int main(){
   ios_base::sync_with_stdio(0);
   cout.precision(2);
   string aux;

   while(fin >> aux){
      if(aux[1] == '=') var[aux[0] - 'a'] = solve(aux.substr(2));
      else  cout << solve(a) << endl;
   }


   return 0;
}
