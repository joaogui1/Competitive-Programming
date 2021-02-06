#include <bits/stdc++.h>

using namespace std;

int p[1010], dp[1010];
pair <int, int> jobs[1010];

int bin_search(int x, int n){
  int ini = 0, fim  = n, mid;
  while(fim - ini > 1){
    mid = (ini + fim)/2;
    if(jobs[mid].first <= x && jobs[mid + 1].first > x) return mid;

    else if(jobs[mid].first > x)  fim = mid;

    else  ini = mid;
  }

  if(jobs[fim].first <= x)  return fim;
  else if(jobs[ini].first <= x) return ini;
  return -1;
}

int f(int n){
  if(n == -1) return 0;
  if(n == 0)  return (jobs[n].first - jobs[n].second);
  if(dp[n] != 0)  return dp[n];

  return dp[n] = max(f(n - 1), jobs[n].first - jobs[n].second + f(p[n]));
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)  scanf("%d %d", &jobs[i].second, &jobs[i].first);
  sort(jobs, jobs + n);

  //for(int i = 0; i < n; ++i)  cout << i << ": " << jobs[i].second << " " << jobs[i].first << endl;

  for(int i = n - 1; i > -1; --i)
    p[i] = bin_search(jobs[i].second, i);

  //for(int i = 0; i < n; ++i)  cout << i << ": " <<p[i] << endl;
  printf("%d\n", f(n - 1));

  return 0;
}
