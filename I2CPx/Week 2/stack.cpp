#include <bits/stdc++.h>
//#define fin cin
//#define fout cout

using namespace std;

stack <int> st;
int main(){
  ifstream fin ("stack.in");
  ofstream fout ("stack.out");
  char op;
  int n, a;
  fin >> n;
  for(int i = 0; i < n; ++i){
    fin >> op;
    if(op == '+'){
      fin >> a;
      st.push(a);
    }
    else{
      a = st.top();
      st.pop();
      fout << a << "\n";
    }
  }





  return 0;
}
