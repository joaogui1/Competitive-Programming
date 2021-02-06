/*
ID: joaogui1
LANG: C++
TASK: snail
*/
#include <fstream>
#include <iostream>
#include <algorithm>
#define ff first
#define ss second

using namespace std;
typedef pair <int, int> pii;

int mark[1 << 7][1 << 7], ans = 0, n;
pii dz[4] = {pii(1, 0), pii(0, -1), pii(-1, 0), pii(0, 1)};

pii operator+(const pii& x, const pii& y) {
    return pii(x.ff + y.ff, x.ss + y.ss);
}

//bool limit(pii p){
//  return (p.ff > -1 && p.ss > -1 && p.ff < n && p.ss < n);
//}

void dfs(pii p, int d, int num){
  //cout << "(" << p.ff << ", " << p.ss << ") " << d << " " << num << endl;
  ans = max(ans, num);
  //mark[p.ff][p.ss] = 1;
  if(mark[p.ff + dz[d].ff][p.ss + dz[d].ss] == 2){
  //  if(p.ff == 5 && p.ss == 1){
    //  cout << limit(p+dz[d]) << endl;
    //  cout << p.ff + dz[d].ff << " " << p.ss + dz[d].ss << endl << endl;
    //}
    p = p + dz[(d + 1)%4];
    if(mark[p.ff][p.ss] == 0){
      mark[p.ff][p.ss] = 1;
      dfs(p, (d + 1)%4, num + 1);
      mark[p.ff][p.ss] = 0;
    }
    p = p + dz[(d + 3)%4]; // anula a soma anterior
    p = p + dz[(d + 3)%4]; //outro giro
    if(mark[p.ff][p.ss] == 0){
      mark[p.ff][p.ss] = 1;
      dfs(p, (d + 3)%4, num + 1);
      mark[p.ff][p.ss] = 0;
    }
    return;
  }
  if(mark[p.ff + dz[d].ff][p.ss + dz[d].ss] == 0){
    mark[p.ff + dz[d].ff][p.ss + dz[d].ss] = 1;
    dfs(p + dz[d], d, num + 1);
    mark[p.ff + dz[d].ff][p.ss + dz[d].ss] = 0;
  }
  return;
}

int main(){
  //ios_base::sync_with_stdio(0);
  ifstream fin ("snail.in");
  ofstream fout ("snail.out");
  int x, m;
  char op;
  fin >> n >> m;
  for(int i = 0; i < 122; ++i)
    for(int j = 0; j < 122; ++j)
      mark[i][j] = 2;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      mark[i][j] = 0;
  for(int i = 0; i < m; ++i){
    fin >> op >> x;
    mark[op -'A' + 1][x] = 2;
  }

  //for(int i = 0; i < n + 1; ++i)
    //for(int j = 0; j < n + 1; ++j)
      //cout << mark[j][i] << " \n"[j == n];
  mark[1][1] = 1;
  dfs(pii(1, 1), 0, 1);
  dfs(pii(1, 1), 3, 1);
  fout << ans << "\n";

  return 0;
}
