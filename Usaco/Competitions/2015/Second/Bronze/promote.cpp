#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  ifstream fin ("promote.in");
  ofstream fout ("promote.out");
  pair<int, int> v[8];
  for(int i = 0; i < 4; ++i)
    fin >> v[i].ff >> v[i].ss;
  fout << v[3].ss + v[2].ss + v[1].ss - v[3].ff - v[2].ff - v[1].ff << "\n";
  fout << v[3].ss + v[2].ss - v[3].ff - v[2].ff << "\n";
  fout << v[3].ss - v[3].ff << "\n";



  return 0;
}
