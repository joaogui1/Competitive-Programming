#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

priority_queue <ll> pq;

int main(){
  ios_base::sync_with_stdio(0);
  ll n, aux[8], auy;
  cin >> n;
  while(n--){
    cin >> auy;
    pq.push(auy);
    if(pq.size() < 3) cout << "-1\n";
    else{
      for(int i = 0; i < 3; ++i)  aux[i] = pq.top(), pq.pop();
      auy = 1;
      for(int i = 0; i < 3; ++i)  auy *= aux[i];
      cout << auy << "\n";
      for(int i = 0; i < 3; ++i)  pq.push(aux[i]);
    }
  }


  return 0;
}
