#include <bits/stdc++.h>

using namespace std;

void mapa(auto x, vector<int> v){
  for(int j = 0; j < x.size(); ++j){
    for(int & k: v)  cout << x[j](k) << " \n"[k == v[v.size() - 1]];
    cout << endl;
  }
  return;
}
vector <int> v;
int main(){
  int n, aux;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> aux;
    v.push_back(aux);
  }
  auto f = [](auto x){ return x*x;};
  auto f2 = [](auto x){ return 2*x;};

  vector <function <int(int)> > func;
  func.push_back(f);
  func.push_back(f2);
  mapa(func, v);


  return 0;
}
