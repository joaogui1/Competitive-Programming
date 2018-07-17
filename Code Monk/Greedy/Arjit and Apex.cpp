#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int a, b;
set <pii> subjects;
vector <pii> new_sub;

void initialize(){
  a = b = 0;
  new_sub.clear();
  subjects.clear();
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, m, g, h, u, v;
  cin >> t;
  auto aux = subjects.begin();
  while(t--){
    cin >> m >> n;
    initialize();
    for(int i = 0; i < m; ++i){
      cin >> u >> v;
      new_sub.push_back(pii(u, v));
    }
    for(int i = 0; i < n; ++i){
      cin >> u >> v;
      subjects.insert(pii(u, v));
    }
    for(pii const & aup : new_sub){
      aux = subjects.upper_bound(aup);
      --aux;
      if((aux -> first) == aup.first) ++a;
      if(*aux == aup) ++b;
    }
    cin >> g >> h;
    if(a >= g && b >= h)  cout << "Great\n";
    else if(a >= g && b < h)  cout << "Good\n";
    else  cout << ":(\n";
  }



  return 0;
}
