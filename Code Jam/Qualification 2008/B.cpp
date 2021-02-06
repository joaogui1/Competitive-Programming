#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

int trains[2][24*60 + 10];

int f(string s){
  return ((s[0] - '0')*10 + (s[1] - '0'))*60 + ((s[3] - '0')*10 + (s[4] - '0'));
}

int main(){
  ios_base::sync_with_stdio(0);
  int na, nb, n, T, hi, mi, hf, mf, ans[2], freed[2];
  string aus;
  cin >> n;
  for(int t = 1; t <= n; ++t){
    for(int i = 0; i < 2; ++i)
      for(int j = 0; j < 24*60; ++j)
        trains[i][j] = 0;
    ans[0] = ans[1] = freed[0] = freed[1] = 0;
    cin >> T >> na >> nb;
    for(int i = 0; i < na; ++i){
      cin >> aus;
      --trains[0][f(aus)];
      cin >> aus;
      ++trains[1][f(aus) + T];
    }
    for(int i = 0; i < nb; ++i){
      cin >> aus;
      cout << f(aus)/60 << ":" << f(aus)%60 << " " << aus << endl;
      --trains[1][f(aus)];
      cin >> aus;
      ++trains[0][f(aus) + T];
    }

    for(int i = 0; i < 24*60; ++i){
      for(int j = 0; j < 2; ++j){
        if(trains[j][i] != 0)  cout << i/60 << ":" << i%60 << " " << j << " " << trains[j][i] <<endl;
        freed[j] += trains[j][i];
        if(freed[j] < 0){
          ans[j] -= +freed[j];
          freed[j] = 0;
        }
      }
    }

    cout << "Case #" << t << ": " << ans[0] << " " << ans[1] << "\n";
  }


  return 0;
}
