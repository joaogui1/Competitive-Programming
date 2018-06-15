//http://codeforces.com/contest/739/problem/E
//O(n²log(n))
#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int op[2048];
double pa[2048], pb[2048], pab[2048], dp[2048];

pii f(int n, double costa, double costb){
  pii ret = pii(0, 0);
  for(int i = 1; i <= n; ++i){
    op[i] = 0;
    dp[i] = dp[i - 1];
      
    if(dp[i] < dp[i - 1] + pa[i] - costa){
      dp[i] = dp[i - 1] + pa[i] - costa;
      op[i] = 1;
    }
    if(dp[i] < dp[i - 1] + pb[i] - costb){
      dp[i] = dp[i - 1] + pb[i] - costb;
      op[i] = 2;
    }
    if(dp[i] < dp[i - 1] + pab[i] - costa - costb){
      dp[i] = dp[i - 1] + pab[i] - costa - costb;
      op[i] = 3;
    }
  }
  
  for(int i = n; i > 0; --i){ //reconstruir a resposta
    if(op[i] > 1) //usei uma ultraball
      ++ret.ss;
    if(op[i] == 1 || op[i] == 3) //usei uma pokeball
      ++ret.ff;
  }
  return ret;
}

pdd find_cost(int n, int a, int b){
  pii aux;
  double inia = 0, fima = 1, mida, inib, midb, fimb;
  for(int i = 0; i < 60; ++i){ 
    mida = (inia + fima)/2;
    inib = 0, fimb = 1;
    for(int j = 0; j < 60; ++j){
      midb = (inib + fimb)/2;
      aux = f(n, mida, midb);
      if(aux.ss == b)	break;
      if(aux.ss > b)// custo do b ta baixo
        inib = midb;
      else //custo do b ta alto
        fimb = midb;
    }
    if(aux.ff == a)	return pdd(mida, midb);
    if(aux.ff > a) // custo do a ta baixo
      inia = mida;
    else // custo do a ta alto
      fima = mida;
  }
  return pdd(mida, midb);
}


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  pdd c;
  int n, a, b, ans;
  cin >> n >> a >> b;
  for(int i = 1; i <= n; ++i) cin >> pa[i];
  for(int i = 1; i <= n; ++i) cin >> pb[i];
  for(int i = 1; i <= n; ++i) pab[i] = pa[i] + pb[i] - pa[i]*pb[i];
    
  c = find_cost(n, a, b);
  cout << fixed << setprecision(10) << dp[n] + c.ff*a  +  c.ss*b << "\n";
  
  
  
  return 0;
}
