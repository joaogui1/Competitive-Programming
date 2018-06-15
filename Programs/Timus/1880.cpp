#include <bits/stdc++.h>

using namespace std;

set <int> s_freq[3];
vector<int> v_freq;

int main(){
  ios_base::sync_with_stdio(0);
  int n, aux;
  for(int j = 0; j < 3; ++j){
    cin >> n;
    for(int i = 0; i < n; ++i){
      cin >> aux;
      if(s_freq[j].count(aux) == 0)  s_freq[j].insert(aux);
    }
  }
  for(set<int>::iterator it = s_freq[0].begin(); it != s_freq[0].end(); ++it){
    aux = 1;
    aux += s_freq[1].count(*it) + s_freq[2].count(*it);
    if(aux == 3) v_freq.push_back(aux);
  }
  cout << v_freq.size() << "\n";


  return 0;
}
