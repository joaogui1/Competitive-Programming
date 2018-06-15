#include <bits/stdc++.h>

using namespace std;

int main(){
   int n, w, h, a, apos[2], b, bpos[2];
   char op;
   cin >> n;
   for(int t = 1; t <= n; ++t){
      int dp[510][510] = {0};
      string input[30], sa, sb;
      cin >> w >> h;
      for(int i = 0; i < w; ++i) cin >> input[i];

      cin >> a;
      cin >> apos[1] >> apos[0];
      sa += input[--apos[1]][--apos[0]];
      while(a--){
         cin >> op;
         if(op == 'E')  ++apos[0];
         else if(op == 'W')   --apos[0];
         else if(op == 'N')   --apos[1];
         else  ++apos[1];
         sa += input[apos[1]][apos[0]];
      }

      cin >> b;
      cin >> bpos[1] >> bpos[0];
      sb += input[--bpos[1]][--bpos[0]];
      while(b--){
         cin >> op;
         if(op == 'E')  ++bpos[0];
         else if(op == 'W')   --bpos[0];
         else if(op == 'N')   --bpos[1];
         else  ++bpos[1];
         sb += input[bpos[1]][bpos[0]];
      }

      for(int i = 0; i < sa.size(); ++i)
         for(int j = 0; j < sb.size(); ++j)
            dp[i][j] = (max((sa[i] == sb[j]) + (i != 0 && j != 0)*dp[i - 1][j - 1], max((i != 0)*dp[i - 1][j], (j != 0)*dp[i][j - 1])));
      cout << "Case " << t << ": " << (sa.size() - dp[sa.size() - 1][sb.size() - 1]) << " " << (sb.size() - dp[sa.size() - 1][sb.size() - 1]) << "\n";

   }



   return 0;
}
