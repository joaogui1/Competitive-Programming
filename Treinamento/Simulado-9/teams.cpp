#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

pii stu[128];
int work[128];

int main(){
  // cin.tie(0);
  // ios_base::sync_with_stdio(0);
  pii aup;
  bool vdc;
  queue<pii> ret;
  int n, q, m, aux;
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> stu[i].ss >> stu[i].ff;
  cin >> q;
  for(int i = 0; i < q; ++i){
    vdc = 1;
    cin >> m;
    if(m > n){
      cout << "0\n";
      continue;
    }
    for(int j = 1; j <= m; ++j) cin >> work[j];
    sort(work + 1, work + m + 1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int j = 1; j <= n; ++j) pq.push(stu[j]);
    for(int j = 1; j <= m && vdc; ++j){
      aux = 0;
      //while(pq.size() && pq.top().ff < work[j]) pq.pop();
      while(pq.size()){
        aup = pq.top(), pq.pop();
        if(aup.ff >= work[j] && aup.ss <= work[j])  ++aux;
        else  ret.push(aup);
        if(aux == work[j]) break;
      }
      if(aux != work[j])  vdc = 0;
      else
        while(ret.size()){
          aup = ret.front(), ret.pop();
          pq.push(aup);
        }
    }
    cout << vdc << "\n";

  }
  return 0;
}
