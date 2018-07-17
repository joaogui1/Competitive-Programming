#include <bits/stdc++.h>

using namespace std;

multiset<int> s;
vector <int> v;

int main(){
  //ios_base::sync_with_stdio(0);
  int n, a;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a;
    v.push_back(a);
    s.insert(a);
  }

  for(int i = 0; i < n - 1; ++i){
    s.erase(s.lower_bound(v[i]));
    a = *(--s.end());
    if(a < v[i])  cout << 0 << " ";
    else  cout << a - v[i] + 1 << " ";
  }
  cout << "0\n";
  return 0;
}
