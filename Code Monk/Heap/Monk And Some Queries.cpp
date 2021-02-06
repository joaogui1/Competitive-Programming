#include <bits/stdc++.h>

using namespace std;

multiset <int> s;

int main(){
  ios_base::sync_with_stdio(0);
  int q, op, x;
  cin >> q;
  while(q--){
    cin >> op;
    if(op == 1){
      cin >> x;
      s.insert(x);
    }
    else if(s.size() == 0)  cout << "-1\n";
    else if(op == 2){
      cin >> x;
      auto aux = s.find(x);
      if(aux == s.end())  cout << "-1\n";
      else  s.erase(aux);
    }
    else if(op == 4) cout << *(s.begin()) << "\n";
    else if(op == 3){
      auto aux = s.end();
      --aux;
      cout << *(aux) << "\n";

    }
  }

  return 0;
}
