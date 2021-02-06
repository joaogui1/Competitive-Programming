#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

int aux;
set <int> ans, act;
vector <pip> events;

void f(){
  for(int i = 0; i < events.size();){
    aux = events[i].ff;
    for(; i < events.size() && events[i].ff == aux; ++i){
      if(events[i].ss.ss == 0)
        act.insert(events[i].ss.ff);

      else
        act.erase(events[i].ss.ff);

    }
    if(act.size() > 0) ans.insert(*(act.begin()));

  }
  return;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ifstream fin ("stampede.in");
  ofstream fout ("stampede.out");
  int n, x, y, r;
  fin >> n;
  for(int i = 0; i < n; ++i){
    fin >> x >> y >> r;
    x *= -r;
    events.push_back(pip(x - r, pii(y, 0)));
    events.push_back(pip(x, pii(y, 1)));
  }

  sort(events.begin(), events.end());

  f();
  fout << ans.size() << "\n";
  return 0;
}
