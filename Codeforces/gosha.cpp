//http://codeforces.com/contest/739/problem/E
//O(n²log(n))
#include <bits/stdc++.h>

using namespace std;

int op[2048][2048];
double pa[2048], pb[2048], pab[2048], dp[2048][2048];

int f(int n, int a, double cost){
  int ret = 0, aux = a;
  for(int i = 1; i <= n; ++i){
    for(int j = 0; j <= a; ++j){
      op[i][j] = 0;
      dp[i][j] = dp[i - 1][j];
      
      if(j > 0 && dp[i][j] < dp[i - 1][j - 1] + pa[i]){
        dp[i][j] = dp[i - 1][j - 1] + pa[i];
        op[i][j] = 1;
      }
      if(dp[i][j] < dp[i - 1][j] + pb[i] - cost){
        dp[i][j] = dp[i - 1][j] + pb[i] - cost;
        op[i][j] = 2;
      }
      if(j > 0 && dp[i][j] < dp[i - 1][j - 1] + pab[i] - cost){
        dp[i][j] = dp[i - 1][j - 1] + pab[i] - cost;
        op[i][j] = 3;
      }
    }
  }
  
  for(int i = n; i > 0; --i){ //reconstruir a resposta
    if(op[i][aux] > 1) //usei uma ultraball
      ++ret;
    if(op[i][aux] == 1 || op[i][aux] == 3) //usei uma pokeball
      --aux;
  }
  return ret;
}

double find_cost(int n, int a, int b){
  int aux;
  double ini = 0.0, fim = 1.0, mid;
  for(int i = 0; i < 50; ++i){ 
    mid = (ini + fim)/2.0;
    aux = f(n, a, mid);
    if(aux > b) // custo ta baixo
      ini = mid;
    else if(aux < b) // custo ta alto
      fim = mid;
  }
  return mid;
}


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  double c;
  int n, a, b, ans;
  cin >> n >> a >> b;
  for(int i = 1; i <= n; ++i) cin >> pa[i];
  for(int i = 1; i <= n; ++i) cin >> pb[i];
  for(int i = 1; i <= n; ++i) pab[i] = pa[i] + pb[i] - pa[i]*pb[i];
    
  c = find_cost(n, a, b);
  cout << fixed << setprecision(10) << dp[n][a] +  c*b << "\n";
  
  
  
  return 0;
}
