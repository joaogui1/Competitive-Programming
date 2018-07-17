#include <bits/stdc++.h>
#define INF 1LL << 60

using namespace std;
typedef long long int ll;

ll G[190][190], H[190];
vector <ll> f, d, p, h;

ll fw(int n){
   for(int i = 0; i < n; ++i) G[i][i] = INF;
   for(int k = 0; k <= n; ++k)
      for(int i = 0; i <= n; ++i)
         for(int j = 0; j <= n; ++j)
            G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
   return G[0][n];
}

void init(){
   f.clear();
   d.clear();
   p.clear();
   h.clear();
   for(int i = 0; i < 190; ++i)  H[i] = 0;
   for(int i = 0; i < 190; ++i)
      for(int j = 0; j < 190; ++j)
         G[i][j] = INF;
}

void make_graph(int n){
   for(int i = 0; i < n; ++i) G[i][i] = f[i];//f[i] + p[i]*d[i];
   H[0] = 0;
   for(int i = 0; i <= n; ++i) H[i] = H[i - 1] + h[i - 1];
   for(int i = 0; i <= n; ++i)
      for(int j = i + 1; j <= n; ++j){
         G[i][j] = G[i][j - 1] + (d[j - 1]*p[i] + d[j - 1]*(H[j - 1] - H[i]));
      }
   return;
}

int main(){
   ios_base::sync_with_stdio(0);
   int n, t = 0;
   ll aux, ans;
   while(cin >> n){
      if(!n)   return n;
      init();
      cout << "Instancia #" << ++t << "\n";
      for(int i = 0; i < n; ++i){
         cin >> aux;
         f.push_back(aux);
         cin >> aux;
         p.push_back(aux);
         cin >> aux;
         h.push_back(aux);
         cin >> aux;
         d.push_back(aux);
      }

      make_graph(n);

      cout << fw(n) << "\n\n";

   }

   return 0;
}
