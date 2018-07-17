#include <bits/stdc++.h>

using namespace std;

set <int> s;
vector <int> v;

int f(int r, int i){
  for(int j = 1;  j <= r; ++j){
    if(v[i] - j >= v[i ])
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  ifstream fin("angry.in");
  ofstream fout("angry.out");
  int n, r, test, best = 0;
  fin >> n;
  v.assign(n, 0);
  for(int i = 0; i < n; ++i)
    fin >> v[i];
  sort(v.begin(), v.end());
  for(int i = 0; i < n; ++i){
    r = 1;
    test = 1;
    while(1){
      if(v[i - 1] <= v[i] - r)
    }
  }


  return 0;
}
