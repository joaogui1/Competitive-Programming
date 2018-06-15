#include <bits/stdc++.h>

using namespace std;

string s[2] = {"This is not an A-sequence.\n", "This is an A-sequence.\n"};
vector <int> v;
int mark[30100];

bool f(){
  mark[0] = 1;
  for(int i = 0; i < v.size(); ++i){
    if(mark[v[i]] == 1) return 0;
    for(int j = 30010 - v[i]; j >= 0; --j)
      if(mark[j])  mark[j + v[i]] = 1;
  }
  return 1;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  bool vdc;
  for(int t = 1; (cin >> n); ++t){
    vdc = 1;
    v.assign(n , 0);
    memset(mark, 0, sizeof mark);
    cout << "Case #" << t << ": ";
    for(int i = 0; i < n; ++i)  cin >> v[i];
    for(int i = 0; i < n - 1; ++i)  if(v[i] >= v[i + 1])  vdc = 0;
    for(int i = 0; i < n; ++i)  cout << v[i] << " \n"[i == n - 1];
    cout << s[f() && vdc];
  }


  return 0;
}
