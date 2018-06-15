#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

string s[312];
deque<int> dq;
vector <pii> pos;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, aux;
  cin >> n;
  for(int i = 0; i < n; ++i){
    dq.push_back(i + 1);
    cin >> s[i];
  }
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < s[i].size() - 1; ++j){
      aux = dq.front();dq.pop_front();
      dq.push_back(aux);
    }
    aux = dq.front();dq.pop_front();
    pos.push_back(pii(aux, i));
  }
  sort(pos.begin(), pos.end());
  for(int i = 0; i < n; ++i)  cout << s[pos[i].ss] << "\n";
  return 0;
}
