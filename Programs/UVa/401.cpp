#include <bits/stdc++.h>

using namespace std;

multiset <double> v;
vector <double> ch[8], sum;

int main(){
  ios_base::sync_with_stdio(0);
  int n, s;
  double av, ans, hp;
  for(int t = 1; cin >> n >> s; ++t){
    ans = av = 0.0;
    sum.assign(n, 0);
    for(int i = 0; i < n; ++i)  ch[i].clear();
    for(int i = 0; i < s; ++i){
      cin >> hp;
      av += hp;
      v.insert(hp);
    }
    av /= n;

    while(v.size() != 2*n)  v.insert(0);
    for(int i = 0; i < n; ++i){
      if(*v.begin() != 0)
        ch[i].push_back(*v.begin());
      sum[i] = *v.begin();
      v.erase(v.begin());

      ch[i].push_back(*(--v.end()));
      sum[i] += *(--v.end());
      v.erase(--v.end());
    }
    for(int i = 0; i < n; ++i)  ans += abs(av - sum[i]);

    cout << "Set #" << t << "\n";
    for(int i = 0; i < n; ++i){
      cout << " " << i << ":";
      for(int j = 0; j < ch[i].size(); ++j)
        if(ch[i][j] != 0) cout << fixed << setprecision(0) << " " << ch[i][j];
      cout << "\n";
    }
    cout << "IMBALANCE = " << fixed << setprecision(5) << ans << "\n\n";
  }



  return 0;
}
