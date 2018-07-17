#include <bits/stdc++.h>

using namespace std;

int is_comp[1024];

void pre(){
  for(int i = 2; i < 1001; ++i)
    if(!is_comp[i])
      for(int j = 2*i; j < 1001; j +=i)
        is_comp[j] = 1;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  pre();
  int n, m, p1, p2, ans;
  cin >> n >> m;
  for(int i = 2; i <= n; ++i) if(!is_comp[i]) p1 = i;
  for(int i = 2; i <= m; ++i) if(!is_comp[i]) p2 = i;
  cout << p1*p2 << "\n";

}
