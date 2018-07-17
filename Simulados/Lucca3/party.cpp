#include <bits/stdc++.h>

using namespace std;
typedef pair <string, int> pis;

int c, val[128];
set <pis> cor;
set <string> ans;

string op1(string s){
  for(int i = 0; i < s.size(); ++i)  s[i] = (s[i] == '0')?'1':'0';
  return s;
}

string op2(string s){
  for(int i = 0; i < s.size(); i += 2)  s[i] = (s[i] == '0')?'1':'0';
  return s;
}

string op3(string s){
  for(int i = 1; i < s.size(); i += 2)  s[i] = (s[i] == '0')?'1':'0';
  return s;
}

string op4(string s){
  for(int i = 0; i < s.size(); i += 3)  s[i] = (s[i] == '0')?'1':'0';
  return s;
}

void dfs(string s, int dist){
  if(dist == c){
    ans.insert(s);
    return;
  }
  string aux = op1(s);
  if(cor.count(pis(aux, dist + 1)) == 0) cor.insert(pis(aux, dist + 1)), dfs(aux, dist + 1);
  aux = op2(s);
  if(cor.count(pis(aux, dist + 1)) == 0) cor.insert(pis(aux, dist + 1)), dfs(aux, dist + 1);
  aux = op3(s);
  if(cor.count(pis(aux, dist + 1)) == 0) cor.insert(pis(aux, dist + 1)), dfs(aux, dist + 1);
  aux = op4(s);
  if(cor.count(pis(aux, dist + 1)) == 0) cor.insert(pis(aux, dist + 1)), dfs(aux, dist + 1);
  return;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string s;
  bool vdc = 0;
  int n, a = 0;
  cin >> n >> c;
  memset(val, -1, sizeof val);
  for(int i = 0; i < n; ++i)  s += '1';
  for(cin >> a; a != -1; cin >> a)  val[a - 1] = 1;
  for(cin >> a; a != -1; cin >> a)  val[a - 1] = 0;

  dfs(s, 0);
  set<string>::iterator it;
  for(it = ans.begin(); it != ans.end(); ++it){
    s = *it;
    for(int i = 0; i < n; ++i){
      if(val[i] != -1 && val[i] + '0' != s[i])  break;
      if(i == n - 1){
        vdc = 1;
        cout << s << "\n";
      }
    }
  }
  if(!vdc)  cout << "IMPOSSIBLE\n";
  return 0;
}
