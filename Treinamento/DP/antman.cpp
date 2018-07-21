#include <bits/stdc++.h>

//using namespace std;
typedef long long int ll;

int sta, end, n;
ll dp[5000][5000], x[5000], inleft[5000], inright[5000], outleft[5000], outright[5000];
static ll INF = 1e16;


ll f(int i, int k){
  if(k < 0) return INF;
  if(i == n - 1){
    if(k != 0)  return INF;
    if(i == sta)  return  x[i] + outleft[i];
    if(i == end)  return  x[i] + inleft[i];
    else  return inleft[i] + outleft[i] + 2*x[i];
  }

  ll ks = i > sta;
  ll ke = i > end;

  ll &ret = dp[i][k];
  if(ret != -1) return ret;
  ret = INF;

  ret = std::min(ret, f(i + 1, k + 1) + (i != sta)*inright[i] + (i!= end)*outright[i] - (i == sta || i == end ? x[i] : 2*x[i]));
  if(i != sta && k + ks > 0)  ret = std::min(ret, f(i + 1, i == end ? k - 1: k) + inleft[i] + outright[i]) + (i == end ? x[i] : 0);
  if(i != end && k + ke > 0) ret = std::min(ret, f(i + 1, i == sta ? k - 1: k) + inright[i] + outleft[i]) + (i == sta ? x[i] : 0);
  if(i != sta && i != end){
    if(k == 0 && ks*ke == 0)  return ret;
    else  if  (k == 1 && ks + ke == 0)  return ret;
    else  ret = std::min(ret, f(i + 1, k - 1) + inleft[i] + outleft[i] + 2*x[i]);
  }

  return ret;
}

int main(){
  std::cin.tie(0);
  memset(dp, -1, sizeof dp);
  std::ios_base::sync_with_stdio(0);
  std::cin >> n >> sta >> end;
  --sta, --end;
  for(int i = 0; i < n; ++i)  std::cin >> x[i];
  for(int i = 0; i < n; ++i)  std::cin >> inright[i];
  for(int i = 0; i < n; ++i)  std::cin >> inleft[i];
  for(int i = 0; i < n; ++i)  std::cin >> outleft[i];
  for(int i = 0; i < n; ++i)  std::cin >> outright[i];

  inleft[sta] = inright[sta] = 0;
  outleft[end] = outright[end] = 0;

  std::cout << f(0, 0) << "\n";

  return 0;
}
