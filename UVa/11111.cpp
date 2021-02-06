#include <bits/stdc++.h>

using namespace std;

vector <int> v;

int f(int l, int r){
  if(l == r - 1){
    if(v[l] == -v[r] && v[r] >= v[l])  return v[r];
    return -1;
  }
  int sz = 0, bg = l + 1, add;
  for(int i = l + 2; i < r; ++i){
    if(v[i] == -v[bg] && v[i] >= v[bg]){
      add = f(bg, i);
      if(add == -1) return -1;
      sz += add;
      bg = ++i;
    }
    if(i != bg && i == r - 1) return -1;
  }
  if(sz >= v[r])  return -1;
  return v[r];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int u;
  string s;
  while(getline(cin, s)){
    v.clear();
    stringstream in;
    in << s;
    while(in >> u)  v.push_back(u);
    u = f(0, v.size() - 1);
    if((v.size()%2) != 0 || v[0] != -v[v.size() - 1])  u = -1;
    if(u != -1) cout << ":-) Matrioshka!\n";
    else  cout << ":-( Try again.\n";
  }

  return 0;
}
