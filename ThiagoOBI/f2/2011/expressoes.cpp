#include <bits/stdc++.h>

using namespace std;

bool close(char a){
  return (a == ')' || a == ']' || a == '}');
}

int open(char a){
  if(a == ')')  return '(';
  if(a == ']')  return '[';
  if(a == '}')  return '{';
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  stack<int> st;
  string s;
  int t, op1, op2, op3, vdc;
  cin >> t;
  while(t--){
    vdc = 1;
    cin >> s;
    op1 = op2 = op3 = 0;
    for(int i = 0; i < s.size(); ++i){
      if(close(s[i])){
        if(st.size() == 0 || st.top() != open(s[i])){
          vdc = 0;
          break;
        }
        if(st.size() != 0)  st.pop();
      }
      else
        st.push(s[i]);
    }
    if(st.size() != 0)  vdc = 0;
    cout << "NS"[vdc] << "\n";
    while(st.size()) st.pop();
  }

  return 0;
}
