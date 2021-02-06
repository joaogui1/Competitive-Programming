#include <bits/stdc++.h>
#define ff first
#define ss second
#ifdef DEBUG
  #define fin cin
  #define fout cout
#endif

using namespace std;

stack <int> st;
bool closed(char a){
  return (a == ']' || a == ')');
}
char opened(char a){
  if(a == ')')  return '(';
  if(a == ']')  return '[';
}
int main(){
  #ifndef DEBUG
    ifstream fin ("brackets.in");
    ofstream fout ("brackets.out");
  #endif
  int vdc;
  string in;
  while(fin >> in){
    vdc = 1;
    for(int i = 0; i < in.size(); ++i){
      if(closed(in[i])){
        if(st.size() && opened(in[i]) == st.top()) st.pop();
        else{
          vdc = 0;
          break;
        }
      }
      else
        st.push(in[i]);
    }
    if(!vdc || st.size()){
      fout << "NO\n";
      while(st.size())  st.pop();
    }
    else
      fout << "YES\n";
  }

  return 0;
}
