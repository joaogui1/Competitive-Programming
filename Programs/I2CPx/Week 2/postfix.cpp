#include <bits/stdc++.h>
#define ff first
#define ss second
#ifdef DEBUG
  #define fin cin
  #define fout cout
#endif

using namespace std;

stack <int> st;

int main(){
  #ifndef DEBUG
    ifstream fin ("postfix.in");
    ofstream fout ("postfix.out");
  #endif
  long long int a, b, c;
  string in;
  getline(fin, in);
  for(int i = 0; i < in.size(); ++i){
    if(in[i] == ' ')
      continue;
    else  if('0' <= in[i] && in[i] <= '9')  st.push(in[i] - '0');
    else{
      a = st.top();st.pop();
      b = st.top();st.pop();
      if(in[i] == '+')
        c = b + a;
      else if(in[i] == '*')
        c = b*a;
      else
        c = b - a;
      st.push(c);
    }
  }
  fout << st.top() << "\n";
  return 0;
}
