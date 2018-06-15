#include <bits/stdc++.h>

using namespace std;

int a[500101], b[500101], ft[500101];
set <int> el;

void upd(int x, int v){
  if(x == 0)  return;
  for(; x < 500100; x += x&-x)  ft[x] += v;
  return;
}

int query(int x){
  if(x == 0)  return 0;
  int ret = 0;
  for(; x > 0; x -= x&-x) ret += ft[x];
  return ret;
}

int find(int val){
  int ans = 0, sum = 0;
  for(int pot = 18; pot > -1; --pot){
    sum = ans + (1 << pot);
    if(sum > 500100)  continue;
    if(ft[sum] > val) continue;
    val -= ft[sum];
    ans = sum;
  }
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) upd(i, 1), el.insert(i);
  for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  for(int i = n; i > 0; --i){
    //a[i] = find(i - b[i]);
    a[i] = find(i - b[i] - 1) + 1;
    upd(a[i], -1);
    el.erase(a[i]);
  }
  for(int i = 1; i <= n; ++i) printf("%d%s", a[i], (i == n)?("\n"):(" "));
  return 0;
}
