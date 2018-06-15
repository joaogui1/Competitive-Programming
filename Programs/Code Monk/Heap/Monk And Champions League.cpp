#include <bits/stdc++.h>

using namespace std;

priority_queue <int> pq;

int main(){
  ios_base::sync_with_stdio(0);
  int n, m;
  long long int ans = 0, aux;
  cin >> m >> n;
  while(m--){
    cin >> aux;
    pq.push(aux);
  }
  while(n--){
    aux = pq.top();pq.pop();
    ans += aux;
    pq.push(aux - 1);
  }
  cout << ans << "\n";

  return 0;
}
