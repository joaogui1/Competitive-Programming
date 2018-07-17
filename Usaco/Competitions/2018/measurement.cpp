#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

pip queries[100100];
map <int, int> cows;

int bin_search(int g){
  int lo = g, hi = 1000000001, mid;
  while(hi - lo > 1){
    mid = lo + (hi - lo)/2;
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ifstream cin ("measurement.in");
  ofstream cout ("measurement.out");
  int a, b, c;
  int n, ans = 0, freq = 1000000000, g, mx;
  cin >> n >> g;
  mx = g;
  for(int i = 0; i < n; ++i){
    cin >> a >> b >> c;
    queries[i] = pip(a, pii(b, c));
  }
  sort(queries, queries + n);
  for(int i = 0; i < n; ++i){
    if(cows.count(queries[i].ss.ff) == 0){
      cows[queries[i].ss.ff] = g + queries[i].ss.ss;
      if(g + queries[i].ss.ss > mx){
        freq = 1;
        mx = g + queries[i].ss.ss;
      }
      else if(g + queries[i].ss.ss == mx) ++freq;
      else{
        if(g == mx){
          --freq;
          if(freq == 0){

          }
        }
      }

    }
  }
  return 0;
}
