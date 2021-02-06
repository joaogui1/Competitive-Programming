#include <bits/stdc++.h>
#define id second
#define tim first

using namespace std;
typedef pair<int, int> pii;

int ans[1024];
priority_queue <pii, vector<pii> , greater<pii> > pq;

int main(){
  pii aux;
  int n, l, t;
  scanf("%d %d", &n, &l);
  for(int i = 1; i <= n; ++i)
    pq.push(pii(0, i));
  for(int i = 0; i < l; ++i){
    scanf("%d", &t);
    aux = pq.top();pq.pop();
    ++ans[aux.id];
    aux.tim += t;
    pq.push(aux);
  }
  for(int i = 1; i <= n; ++i)
    printf("%d %d\n", i, ans[i]);

  return 0;
}
