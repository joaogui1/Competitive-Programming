#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

map <int, string> translate;
pair<int, pii> cubes[1 << 12];
int aux[10], ans, pai[1 << 12], dp[1 << 12], cont = 0;


void initialize(){
  ++cont;
  ans = 0;
  memset(pai, -1, sizeof pai);
  for(int i = 0; i < 1 << 12; ++i)  dp[i] = 1;
}

void print_ans(int x){
  if(pai[x] != -1)  print_ans(pai[x]);
  cout << cubes[x].first + 1 << " " << translate[x%6] << "\n";
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, m;
  translate[0] = "front";
  translate[1] = "back";
  translate[2] = "left";
  translate[3] = "right";
  translate[4] = "top";
  translate[5] = "bottom";
  while(1){
    cin >> n;
    if(n == 0)  return 0;
    initialize();
    m = 0;
    for(int i = 0; i < n; ++i){
      for(int j =  0; j < 6; ++j)
        cin >> aux[j];

      for(int j = 0; j < 6; ++j){
        cubes[m].first = i;
        cubes[m].second.first = aux[j];
        cubes[m].second.second = ((j%2)?(aux[j - 1]):(aux[j + 1]));
        ++m;
      }
    }

    //for(int i = 0; i < 6*n; ++i)  cout << cubes[i].first << ":" << cubes[i].second.first << ":" << cubes[i].second.second << " \n"[(i % 6) == 5];

    for(int i = 0; i < 6*n; ++i)
      for(int j = 0; j < i; ++j){
        if(cubes[j].first < cubes[i].first && cubes[j].second.second == cubes[i].second.first && dp[i] < dp[j] + 1){
          dp[i] = dp[j] + 1;
          pai[i] = j;
          if(dp[i] > dp[ans]) ans = i;
      }
    }
    //cout << ans << endl;
    //cout << cubes[ans].second.first << " " << cubes[ans].second.second << endl;

    if(cont > 1)  cout << "\n";
    cout << "Case #" << cont << "\n" << dp[ans] << "\n";
    print_ans(ans);
  }



  return 0;
}
