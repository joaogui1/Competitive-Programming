#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> e;
vector <vector <int> > sol;

void build(int u, int v, int w){
  int test;
  vector <int> x;
  x.push_back(u);
  x.push_back(v);
  x.push_back(w);
  multiset <int> act;
  for(int i = 0; i < e.size(); ++i)
    act.insert(e[i]);
  if(act.find(u + v) != act.end())  act.erase(act.find(u + v));
  if(act.find(u + w) != act.end())  act.erase(act.find(u + w));
  if(act.find(w + v) != act.end())  act.erase(act.find(v + w));
  multiset<int>::iterator it = act.begin();
  for(int i = 3; i < n; ++i){
    test = *(act.begin()) - x[0];
    if(test <= x.back())  return;

    for(int i = 0; i < x.size(); ++i){
      it = act.find(x[i] + test);
      if(it == act.end()) return;
      act.erase(it);
    }
    x.push_back(test);
  }
  sol.push_back(x);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int aux;
  cin >> n;
  for(int i = 0; i < n*(n - 1)/2; ++i){
    cin >> aux;
    e.push_back(aux);
  }
  sort(e.begin(), e.end());
  for(int i = 2; i < n; ++i){
    if(i > 2 && e[i] == e[i - 1]) continue;
    if(e[0] + e[1] <= e[i])  break;
    if(((e[0] + e[1] + e[i])&1) == 0) build((e[0] + e[1] - e[i])/2, (e[i] + e[0] - e[1])/2, (e[i] + e[1] - e[0])/2);
  }
  cout << sol.size() << "\n";
  for(int i = 0; i < sol.size(); ++i){
    for(int j = 0; j < sol[i].size(); ++j)
      cout << sol[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
