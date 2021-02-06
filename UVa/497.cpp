#include <bits/stdc++.h>

using namespace std;

int pai[1 << 21], pos[1 << 21];
vector <int> lis, input, sz;

int f(){
  int p;
  vector<int>::iterator it;
  for(int i = 0; i < input.size(); ++i){
    it = lower_bound(sz.begin(), sz.end(), input[i]);
    p = (it - sz.begin());

    if(it == sz.end())  sz.push_back(input[i]);
    else  *it = input[i];

    pos[p] = i;
    if(p == 0)  pai[i] = -1;
    else  pai[i] = pos[p - 1];
  }
  return sz.size();
}

void initialize(){
  sz.clear();
  lis.clear();
  input.clear();
  memset(pai, 0, sizeof pai);
  memset(pos, 0, sizeof pos);
  return;
}

int main(){
  ios::sync_with_stdio(0);
  int n, ex, num, p;
  string aux;
  cin >> n;
  getline(cin, aux);
  getline(cin, aux);
  for(int i = 0; i < n; ++i){
    initialize();
    while(1){
      getline(cin, aux);
      if(aux.size() == 0) break;
      ex = 1;
      num = 0;
      for(int j = aux.size() - 1; j > -1; --j){
        num += (aux[j] - '0')*ex;
        ex *= 10;
      }
      input.push_back(num);
    }
    if(i != 0)  cout << "\n";
    cout << "Max hits: " << f() << "\n";

    p = pos[sz.size() - 1];
    while(p > -1){
      lis.push_back(input[p]);
      p = pai[p];
    }
    for(int j = lis.size() - 1; j > -1; --j)  cout << lis[j] << "\n";
  }
  return 0;
}
