#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

vector<pii> mov;
vector<int> lang;
map <int, int> freq;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, a, b, idx = 0;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> m;
    lang.push_back(m);
    if(freq.count(m)) ++freq[m];
    else  freq[m] = 1;
  }
  cin >> m;
  for(int i = 0; i < m; ++i){
    cin >> a;
    mov.push_back(pii(a, 0));
  }

  for(int i = 0; i < m; ++i){
    cin >> a;
    mov[i].ss = a;
  }

  for(int i = 1; i < m; ++i)
    if(freq[mov[i].ff] > freq[mov[idx].ff] || (freq[mov[i].ff] == freq[mov[idx].ff] && freq[mov[i].ss] > freq[mov[idx].ss]))  idx = i;

  cout << idx + 1 << "\n";

  return 0;
}
