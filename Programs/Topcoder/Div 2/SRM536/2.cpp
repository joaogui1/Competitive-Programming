#include <bits/stdc++.h>

using namespace std;

class RollingDiceDivTwo{
  public:
     int minimumFaces(vector <string> rolls){
       int n = rolls[0].size(), ans = 0;
       vector <int> dice(n, 0);
       for(int i = 0; i < roll.size(); ++i){
         vector <int> faces;
         for(int j = 0; j < rolls[i].size(); ++j) faces.push_back(rolls[i][j] - '0');
         sort(faces.begin(), faces.end());
         for(int j = 0; j < n; ++j) dice[j] = max(dice[j], faces[j]);
       }
       for(int j = 0; j < n; ++j) ans += dice[j];
       return ans;
     }
};
