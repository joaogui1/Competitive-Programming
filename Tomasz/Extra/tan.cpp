#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

int n;
vector <ll> v;
vector <int> dir, esq;
priority_queue<pll, vector<pll>, greater<pll> > pq;

void annihilate(int pos){
  if(dir[pos] > -1 && dir[pos] <= n + 2)  esq[dir[pos]] = esq[pos];
  if(esq[pos] > -1 && esq[pos] <= n + 2)  dir[esq[pos]] = dir[pos];
  esq[pos] = dir[pos] = -1;
}

bool sign(long long int x){
  return (x > 0);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll sum = 0, a;
  int m, aux = 0;
  cin >> n >> m;
  v.assign(n + 4, 0);
  esq.assign(n + 4, 0);
  dir.assign(n + 4, 0);
  esq[0] = -1, dir[0] = 1, v[0] = -(1LL << 45);
  esq[n + 1] = n, dir[n + 1] = n + 2, v[n + 1] = -(1LL << 45);
  for(int i = 1; i <= n; ++i){
    cin >> v[i];
    esq[i] = i - 1;
    dir[i] = i + 1;
  }

  for(int i = 1; i <= n + 1; ++i)
    if(sign(v[i]) == sign(v[i - 1]) || v[i] == 0 || v[i - 1] == 0){
      v[i] += v[i - 1];
      annihilate(i - 1);
    }

  for(int i = 1; i <= n; ++i){
    if(dir[i] == -1)  continue;
    pq.push(pll(abs(v[i]), i));
    if(sign(v[i]))
      ++aux;
  }


  while(aux > m){
    a = (pq.top()).ss;
    pq.pop();
    if(dir[a] == -1)  continue;
    --aux;
    if(esq[a] > -1){
      v[a] += v[esq[a]];
      annihilate(esq[a]);
    }
    if(dir[a] < n + 2){
      v[a] += v[dir[a]];
      annihilate(dir[a]);
    }
    pq.push(pll(abs(v[a]), a));
  }
  for(int i = 1; i <= n; ++i)
    if(dir[i] != -1 && sign(v[i]))
      sum += v[i];
  cout << sum << "\n";
  return 0;
}
