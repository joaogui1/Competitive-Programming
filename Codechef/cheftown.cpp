#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

int h[400100];
deque<pii> mn, mx;

void addmn(pii a){
  while(mn.size() && a.ff < mn.back().ff) mn.pop_back();

  mn.push_back(a);
}

void addmx(pii a){
  while(mx.size() && a.ff > mx.back().ff)  mx.pop_back();
  mx.push_back(a);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, w, ans = 0;
  cin >> n >> w;
  for(int i = 1; i <= n; ++i) cin >> h[i];
  for(int i = 0; i < w; ++i) addmn(pii(h[i], i)), addmx(pii(h[i], i));
  for(int i = w; i <= n; ++i){
    addmn(pii(h[i], i)), addmx(pii(h[i], i));
    if(mn.front().ss == i - w)  mn.pop_front();
    if(mx.front().ss == i - w)  mx.pop_front();
    if(mx.front().ff - mn.front().ff + 1 == w) ++ans;
  }

  cout << ans << "\n";

  return 0;
}
