#include <bits/stdc++.h>

using namespace std;

int d[2000100];
map <int, int> freq;
int main(){
  int n, a, b, ans = 2000010, sum = 0, old = 0, tst, beg, aux;
  freopen("g.in", "r", stdin);
  freopen("g.out", "w", stdout);
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%d %d", &a, &b), d[i] = b - a;
  for(int i = n + 1; i <= 2*n; ++i) d[i] = d[i - n];
  sum = 0;
  for(int i = 1; i <= n; ++i){
    sum += d[i];
    freq[sum]++;
  }

  tst = 0;
  for(auto &el : freq){
    if(el.second > tst){
      tst = el.second;
      aux = el.first;
    }
  }
  sum = 0;
  for(int i = 1; i <= n; ++i){
    sum += d[i];
    if(sum == aux){
      beg = i;
      break;
    }
  }

  old = 0;
  tst = sum = 0;
  for(int i = 1; i <= n; ++i){
    sum += d[beg + i];
    if(sum == 0){
      tst += i - old - 1;
      old = i;
    }
  }
  ans = min(ans, tst);


  printf("%d\n", ans);

  return 0;
}
