#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

string s;
ll jhash[2][100100], base[2] = {33, 163}, MOD[2] = {1000000009, 1000000007}, pot[2][100100];

ll gethash(int idx, int l, int r){
  ll ret = (jhash[idx][r] - (jhash[idx][l - 1]*pot[idx][r - l + 1])%MOD[idx] + MOD[idx])%MOD[idx];
  return ret;
}

void initialize(){
  memset(jhash, 0, sizeof jhash);
  int n = s.size();
  pot[0][0] = pot[1][0] = 1;
  for(int i=1;i<=n;i++)
    for(int j = 0; j < 2; ++j)
      pot[j][i] = (base[j]*pot[j][i - 1])%MOD[j];

  for(int i=1;i<=n;i++)
    for(int j = 0; j < 2; ++j)
      jhash[j][i] = (base[j]*jhash[j][i - 1] + (s[i - 1] - 'a' + 1))%MOD[j];
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int q, l[4], r[4];
  bool read = 0;
  cin >> s >> q;
  initialize();

  while(q--){
    cin >> l[0] >> r[0] >> l[1] >> r[1];
    if(r[0] - l[0] == r[1] - l[1]){
      if(gethash(0, l[0], r[0]) == gethash(0, l[1], r[1]) && gethash(1, l[0], r[0]) == gethash(1, l[1], r[1]))  cout << "Yes\n";
      else  cout << "No\n";
    }
    else  cout << "No\n";
  }



  return 0;
}
