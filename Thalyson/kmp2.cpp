#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<char, int> pci;

int vv;
vector<pci> kmp;
string virus, s[2], dp[110][110][110];

string mm(string a, string b){
  return a.size() > b.size()?a:b;
}

void f(){
  kmp.push_back(pci('@', -1));
  for(int i = 0; i < virus.size(); ++i){
    kmp.push_back(pci(virus[i], 0));
    for(int j = kmp[i].ss; j != -1; j = kmp[j].ss){
      if(kmp[j + 1].ff == virus[i]){
        kmp[i + 1].ss = j + 1;
        break;
      }
    }
  }
  return;
}

string g(int p1, int p2, int v){
  if(dp[p1][p2][v] != "!") return dp[p1][p2][v];
  if(p1 >= s[0].size() || p2 >= s[1].size()) return dp[p1][p2][v] = "";

  dp[p1][p2][v] = mm(g(p1 + 1, p2, v), g(p1, p2 + 1, v));;

  if(s[0][p1] == s[1][p2]){

    vv = v;
    while(vv != -1 && kmp[vv + 1].ff != s[0][p1]) vv = kmp[vv].ss;
    ++vv;

    if(vv == virus.size())  return dp[p1][p2][v];
    dp[p1][p2][v] = mm(dp[p1][p2][v], s[0][p1] + g(p1 + 1, p2 + 1, vv));
  }

  return dp[p1][p2][v];
}

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(0);
  int sz;
  cin >> s[0] >> s[1] >> virus;

  for(int i = 0; i < 108; ++i)
    for(int j = 0; j < 108; ++j)
      for(int k = 0; k < 108; ++k)
        dp[i][j][k] = "!";

  f();
  if(g(0, 0, 0).size() == 0) cout << 0 << "\n";
  else cout << g(0, 0, 0) << "\n";

  return 0;
}
