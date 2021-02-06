#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

string a, b;
vector <pii> intervals;
int dp[1100][1100], final_dp[1100];


int main(){
  ios_base::sync_with_stdio(0);
  int k;
  while(1){
    cin >> k;
    if(k == 0)  break;
    cin >> a >> b;

    for(int i = 0; i < a.size(); ++i) dp[i][0] = (a[i] == b[0]);
    for(int i = 0; i < b.size(); ++i) dp[0][i] = (a[0] == b[i]);

    for(int i = 1; i < a.size(); ++i)
      for(int j = 1; j < b.size(); ++j)
        if(a[i] == b[j])  dp[i][j] = 1 + dp[i - 1][j - 1];

    for(int i = 0; i < a.size(); ++i)
      for(int j = 0; j < b.size(); ++j)
        if(dp[i][j] >= k) intervals.push_back(pii(i,  dp[i][j]));

    //for(int i = 0; i < a.size(); ++i)
      //for(int j = 0; j < b.size(); ++j)
        //cout << dp[i][j] << " \n"[j == b.size() - 1];

    //sort(intervals.rbegin(), intervals.rend());

    for(int i = 0; i < a.size(); ++i){
      final_dp[i] = (i != 0)?(final_dp[i - 1]):(0);
      for(int j = 0; j < intervals.size(); ++j)
        if(intervals[j].first == i) final_dp[i] = max(final_dp[i], intervals[j].second + final_dp[intervals[j].first - intervals[j].second + 1]);
    }
    for(int i = 0; i < a.size(); ++i) cout << final_dp[i] << " \n"[i == a.size() - 1];
    cout << final_dp[a.size() - 1] << endl;

  }


  return 0;
}
