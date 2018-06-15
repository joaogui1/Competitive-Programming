#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int zeroes;
ll best, worst;
vector <ll> pos, neg;

void initialize(){
  pos.clear();
  neg.clear();
  best = worst = zeroes = 0;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, t;

  cin >> t;
  while(t--){
    cin >> n;
    initialize();
    for(int i = 0; i < n; ++i){
      cin >> aux;
      if(aux > 0) pos.push_back(aux);
      else if(aux == 0) ++zeroes;
      else  neg.push_back(aux);
    }

    for(ll mask = 1; mask < (1 << neg.size()); ++mask){
      test = 1;
      for(ll i = 0; i < neg.size(); ++i)
        if((1LL << i)&mask)  test *= neg[i];

      best = max(best, test);
      worst = min(worst, test);
    }
    if(neg.size() == 0){
      if(zeroes > 0)  worst = 0;

    }

  }



  return 0;
}
