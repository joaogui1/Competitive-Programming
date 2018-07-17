#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

priority_queue<pii> pq;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  pii aup, app;
  int k, t, a;
  cin >> k >> t;
  for(int i = 0; i < t; ++i){
    cin >> a;
    pq.push(pii(a, i));
  }
  a = -1;
  while(pq.size() > 1){
    aup = pq.top();pq.pop();
    if(a == aup.ss){
      app = pq.top();
      pq.pop();
      swap(aup, app);
      pq.push(app);
    }
    a = aup.ss;
    --(aup.ff);
    if(aup.ff != 0) pq.push(aup);
  }
  cout << (pq.top().ff - 1) << "\n";
  return 0;
}
