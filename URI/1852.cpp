#include <bits/stdc++.h>

using namespace std;

set <int> free_stark, free_wolf;
map <string, int> starks, wolves;
map <int, string> _wolves, _starks;
map <int, int> pairs_stark, pairs_wolf, pref_stark[1 << 8], pref_wolf[1 << 8];

int main(){
  ios_base::sync_with_stdio(0);
  int n, aux, aux_wolf;
  string child, wolf;
  cin >> n;

  cin >> child;
  starks[child] = 0;
  _starks[0] = child;
  for(int j = 0; j < n; ++j){
    cin >> wolf;
    wolves[wolf] = j;
    _wolves[j] = wolf;
    pref_stark[0][j] = j;
  }
  for(int i = 1; i < n; ++i){
    cin >> child;
    starks[child] = i;
    _starks[i] = child;
    for(int j = 0; j < n; ++j){
      cin >> wolf;
      pref_stark[i][j] = wolves[wolf];
    }
  }

  for(int i = 0; i < n; ++i){
    cin >> wolf;
    for(int j = 0; j < n; ++j){
      cin >> child;
      pref_wolf[wolves[wolf]][starks[child]] = j;
    }
  }

  for(int i = 0; i < n; ++i)  free_stark.insert(i), free_wolf.insert(i);

  while(free_stark.size()){
    aux = *(free_stark.begin());
    free_stark.erase(aux);
    for(int i = 0; i < n; ++i){
      aux_wolf = pref_stark[aux][i];
      if(free_wolf.count(aux_wolf)){
        pairs_stark[aux] = aux_wolf;
        pairs_wolf[aux_wolf] = aux;
        free_wolf.erase(aux_wolf);
        break;
      }
      else if(pref_wolf[aux_wolf][aux] < pref_wolf[aux_wolf][pairs_wolf[aux_wolf]]){
        pairs_stark[pairs_wolf[aux_wolf]] = -1;
        free_stark.insert(pairs_wolf[aux_wolf]);
        pairs_wolf[aux_wolf] = aux;
        pairs_stark[aux] = aux_wolf;
        break;
      }
    }
  }

  for(int i = 0; i < n; ++i)  cout << _starks[i] << " " << _wolves[pairs_stark[i]] << "\n";

  return 0;
}
