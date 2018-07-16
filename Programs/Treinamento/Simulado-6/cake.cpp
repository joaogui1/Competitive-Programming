#include <bits/stdc++.h>

using namespace std;

vector <int> pos;
double del[25100];
bool comp(int a, int b){
    return del[a] > del[b];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, q, a;
  char op;
  cin >> n >> a;
  pos.resize(n);
  for(int i = 1; i <= n; ++i) cin >> del[i], pos[i - 1] = i;
  sort(pos.begin(), pos.end(), comp);
  while(pos.size() > 10)  pos.pop_back();

  cin >> q;
  while(q-->0){
    
  }

  return 0;
}
