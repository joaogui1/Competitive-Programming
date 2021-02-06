#include <bits/stdc++.h>

using namespace std;

class  FarmvilleDiv2{
  public:
    int minTime(vector <int> time, vector <int> cost, int bud){
      int ret = 0;
      vector<pair <int, int> > v;
      for(int i = 0; i < time.size(); ++i)
        v.push_back(pair <int, int>(cost[i], time[i]));
      sort(v.begin(), v.end());
      for(int i = 0; i < v.size(); ++i){
         if(bud >= v[i].first*(v[i].second - 1)){
           bud -= v[i].first*(v[i].second - 1);
           ret += 1;
         }
         else if(bud < v[i].first)  ret += v[i].second;
         else{
           v[i].second -= bud/v[i].first;
           bud = 0;
           ret += v[i].second;
         }
      }
      cout << ret << "\n";
    }
};
