#include <bits/stdc++.h>

using namespace std;

int G[210][210];

void fw(){
    for(int k = 1; k <= 200; ++k)
      for(int i = 1; i <= 200; ++i)
         for(int j = 1; j <= 200; ++j)
            G[i][j] |= (G[i][k] & G[k][j]);
}

int main(){
   ios_base::sync_with_stdio(0);
   int n, a, b;
   string input;
   while(1){
      cin >> n;
      if(!n)  break;
      memset(G, 0, sizeof(G));
      while(1){
         cin >> a >> b;
         if(a == 0 || b == 0) break;
         cin >> input;
         for(int i = 0; i < input.size(); ++i)  G[a][b] |= (1 << (input[i] - 'a'));
      }
      fw();
      while(1){
         cin >> a >> b;
         if(a == 0 || b == 0) break;
         bool p = 0;
         string ans;
         for(int i = 0; i < 26; ++i)
            if(G[a][b] & (1 << i)){
               ans += (char)('a' + i);
               p = 1;
            }
         cout << (p?ans:"-");
         cout << "\n";
      }
      cout << "\n";
   }


   return 0;
}
