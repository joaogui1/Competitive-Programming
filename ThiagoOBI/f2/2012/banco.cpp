#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

vector <pii> v;
priority_queue <int, vector<int>, greater<int> > pq;

int main(){
  pii aup;
  int c, n, t, d, ans = 0;
  scanf("%d %d", &c, &n);
  for(int i = 0; i < c; ++i)  pq.push(0);
  for(int i = 0; i < n; ++i){
    scanf("%d %d", &t, &d);
    v.push_back(pii(t, d));
  }
  sort(v.begin(), v.end());
  t = 0;
  for(int i = 0; i < v.size(); ++i){
    t = v[i].ff;
    c = pq.top();
    pq.pop();
    if(c > t){
      if(c - t > 20){
        ++ans;
        }
      t = c;
    }
    pq.push(t + v[i ].ss);
  }
  printf("%d\n", ans);
  return 0;
}
