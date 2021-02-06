#include <bits/stdc++.h>

using namespace std;

vector<int> boxes[32];
int dp[32], k, next[32];

bool comp(int a, int b){
  for(int i = 0; i < boxes[a].size() - 1; ++i)
    if(boxes[a][i] <= boxes[b][i])  return 0;
  return 1;
}

int f(int x){
  if(x > k - 1) return 0;
  if(dp[x] != -1)  return dp[x];
  int best = 0;
  for(int i = 1; i < k - x; ++i)
    if(comp(x + i, x))
      if(f(i + x) > best){
        best = f(i + x);
        next[x] = x + i;
      }

  return dp[x] = 1 + best;

}

void f(){
  int best = -1, idx;
  for(int i = 0; i < k; ++i){
    if(f(i) > best){
      idx = i;
      best = f(i);
    }
  }
  cout << best << "\n";
  for(; idx != -1; idx = next[idx]) cout << boxes[idx][boxes[idx].size() - 1] << " ";
  cout << "\n";
  return;
}

void initialize(){
  memset(next, -1, sizeof next);
  for(int i = 0; i < 32; ++i) dp[i] = -1;
  for(int i = 0; i < 32; ++i) boxes[i].clear();
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, aux;
  while(cin >> k){
    initialize();
    cin >> n;
    for(int i = 0; i < k; ++i){
      for(int j = 0; j < n; ++j){
        cin >> aux;
        boxes[i].push_back(aux);
      }
      sort(boxes[i].begin(), boxes[i].end());
      boxes[i].push_back(i + 1);
    }
    for(int i = 0; i < k; ++i)
      for(int j = i + 1; j < k; ++j)
        if(comp(i, j))  swap(boxes[i], boxes[j]);
    f();
}



  return 0;
}
