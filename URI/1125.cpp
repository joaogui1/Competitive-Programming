#include <bits/stdc++.h>

using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   int g, p, s, k;
   while(1){
      cin >> g >> p;
      if(g + p == 0)  break;
      int places[110][110];
      vector < pair <int, int > > points;
      for(int j = 1; j <= g; ++j)
         for(int i = 1; i <= p; ++i)   cin >> places[j][i];
      cin >> s;

      for(int i = 0; i < s; ++i){
         points.clear();
         cin >> k;
         int sist[110] = {0};

         for(int j = 1; j <= k; ++j)
            cin >> sist[j];

         for(int j = 1; j <= p; ++j)
            points.push_back(pair <int, int> (0, j));

         for(int j = 1; j <= g; ++j){
            for(int i = 0; i < p; ++i)
               points[i].first -= sist[places[j][i + 1]];
         }
         //cout << "ok\n";

         sort(points.begin(), points.end());
         cout << points[0].second;
         for(int i = 1; i < points.size(); ++i)
            if(points[i].first == points[0].first)   cout << " " << points[i].second;
         cout << "\n";
      }



   }




   return 0;
}
