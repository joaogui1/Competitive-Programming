#include <bits/stdc++.h>
#include "icc.h"

using namespace std;

vector <int> v[101];
int cnt = 0;

int quera(int sza, int szb, vector<int> a, vector<int> b){
  return query(sza, szb, a.data(), b.data());
}

void setup(int n){
  for(int i = 1; i <= n; ++i) v[i].push_back(i);
}

void join(vector <int> &a, vector <int> &b){
  for(int i = 0; i < b.size(); ++i) a.push_back(b[i]);
}

int bin_search(int idx, int ed){
  int beg = idx + 1, fim = ed, m;
  while(fim > beg){
    cout << fim << " " << beg << "\n";
    vector<int> aux;
    m = (beg + fim)/2;
    for(int i = beg; i <= m; ++i) join(aux, v[i]);

    if(quera(v[idx].size(), aux.size(), v[idx], aux)) fim = m;
    else  beg = m + 1;
  }
  return beg;
}

void run(int n){
  setup(n);
  int ed = n, ans, idx, jdx;
  for(idx = 1; idx <= ed; ++idx){
    vector <int> aux;
    // aux.clear();
    for(int j = idx + 1; j <= ed; ++j)  join(aux, v[j]);
    ans = quera(v[idx].size(), aux.size(), v[idx], aux);
    if(ans == 1)  break;
  }

  jdx = bin_search(idx, ed);

  vector<int> aux[2];
  aux[0].resize(1), aux[1].resize(1);
  for(int i = 0; i < v[idx].size(); ++i){
    aux[0][0] = v[idx][i];
    ans = quera(1, v[jdx].size(), aux[0], v[jdx]);
    if(ans == 1)  break;

  }

  for(int i = 0; i < v[jdx].size(); ++i){
    aux[1][0] = v[jdx][i];
    ans = quera(1, 1, aux[0], aux[1]);
    if(ans == 1)  break;
  }

  setRoad(aux[0][0], aux[0][1]);
  join(v[idx], v[jdx]);
  swap(v[ed], v[jdx]);
  --ed;

}
