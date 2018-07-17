#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef tuple <ll, ll, ll, ll> tll;

priority_queue<tuple<ll, ll, ll, ll>, vector<tll>, greater<tll> > pq;

int main(){
  ios_base::sync_with_stdio(0);
  int n, c, p;
  ll aux;
  tll aut;
  cin >> c >> p >> n;
  for(int i = 0; i < c; ++i)  pq.push(tll(0, i + 1, 0, 0));
  for(int i = 0; i < n; ++i){
    cin >> aux;
    aut = pq.top();pq.pop();
    get<3>(aut) += 1;
    get<0>(aut) = get<3>(aut)*(aux + get<2>(aut));
    get<2>(aut) = aux;
    pq.push(aut);
  }
  int i = 0;
  while(cin >> aux){
    aut = pq.top();pq.pop();
    cout << get<1>(aut) << " ";
    get<3>(aut) += 1;
    get<0>(aut) = get<3>(aut)*(aux + get<2>(aut));
    get<2>(aut) = aux;
    pq.push(aut);
    ++i;
  }
  for(;i < p; ++i){
    aux = 0;
    aut = pq.top();pq.pop();
    cout << get<1>(aut) << " ";
    get<3>(aut) += 1;
    get<0>(aut) = get<3>(aut)*(aux + get<2>(aut));
    get<2>(aut) = aux;
    pq.push(aut);
  }
  cout << "\n";
  return 0;
}
