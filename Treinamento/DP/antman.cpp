#include <bits/stdc++.h>

//using namespace std;
typedef long long int ll;

int sta, end, n;
ll dp[5000][5000], x[5000], inleft[5000], inright[5000], outleft[5000], outright[5000];
static ll INF = 1e18;


ll f(int i, ll k){
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

  if(i == sta){
    ret = std::min(ret, f(i + 1, k) + outright[i] - x[i]);
    ret = std::min(ret, f(i + 1, k - 1) + outleft[i] + x[i]);
  }
  if(i == end){
    ret = std::min(ret, f(i + 1, k) + inright[i] - x[i]);
    ret = std::min(ret, f(i + 1, k - 1) + inleft[i] + x[i]);
  }
  if(i != sta && i != end){
    ret = std::min(ret, f(i + 1, k + 1) + inright[i] + outright[i] - 2*x[i]);
    if(k + ks)  ret = std::min(ret, f(i + 1, k) + inleft[i] + outright[i]);
    if(k + ke)  ret = std::min(ret, f(i + 1, k) + inright[i] + outleft[i]);
    if(k > 1)  ret = std::min(ret, f(i + 1, k - 1) + inleft[i] + outleft[i] + 2*x[i]);
    if(k > 0 && (ke || ks))  ret = std::min(ret, f(i + 1, k - 1) + inleft[i] + outleft[i] + 2*x[i]);
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
  for(int i = 0; i < n; ++i)  std::cin >> inleft[i];
  for(int i = 0; i < n; ++i)  std::cin >> inright[i];
  for(int i = 0; i < n; ++i)  std::cin >> outleft[i];
  for(int i = 0; i < n; ++i)  std::cin >> outright[i];

  std::cout << f(0, 0) << "\n";

  return 0;
}
