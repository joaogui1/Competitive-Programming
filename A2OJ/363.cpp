#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<string, string> pss;

string aux, auy, auz;
pss in[10010];
map <pss, string> mp;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, u;
    cin >> n;
    for(int i = 0; i < n; ++i){
      cin >> in[i].ff >> in[i].ss >> aux;
      mp[in[i]] = aux;
    }
    cin >> u;
    for(int i = 0; i < u; ++i){
      cin >> aux >> auy >> auz;
      mp[pss(aux, auy)] = auz;
    }

    for(int i = 0; i < n; ++i)
      cout << in[i].ff << " " << in[i].ss << " " << mp[in[i]] << "\n";


  return 0;
}
