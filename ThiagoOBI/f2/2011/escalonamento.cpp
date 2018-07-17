#include <bits/stdc++.h>

using namespace std;

int in[100100];
vector <int> out[100100], ans;
priority_queue< int, vector <int>, greater <int> > pq;

int main(){
  int n, m, u, v;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i){
    scanf("%d %d", &u, &v);
    ++in[v];
    out[u].push_back(v);
  }
  for(int i = 0; i < n; ++i)
    if(in[i] == 0)  pq.push(i);
  while(pq.size()){
    u = pq.top();
    pq.pop();
    ans.push_back(u);
    for(int i = 0; i < out[u].size(); ++i){
      v = out[u][i];
      --in[v];
      if(in[v] == 0)
        pq.push(v);
    }
  }
  if(ans.size() < n)
    printf("*\n");
  else for(int i = 0; i < ans.size(); ++i)
    printf("%d\n", ans[i]);

  return 0;
}
