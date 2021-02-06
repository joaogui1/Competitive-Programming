#include <bits/stdc++.h>

using namespace std;

vector <int> u, v;

int main(){
  int n, c, xi, xf, id, ego;
  scanf("%d %d", &n, &c);
  for(int i = 0; i < n; ++i){
    scanf("%d %*d %d %*d", &xi, &xf);
    u.push_back(min(xi, xf));
    v.push_back(max(xi, xf));
  }

  sort(u.begin(), u.end());
  sort(v.begin(), v.end());

  for(int i = 0; i < c; ++i){
    scanf("%d %d", &xi, &xf);
    id = lower_bound(u.begin(), u.end(), xi) - u.begin();
    ego = v.end() - upper_bound(v.begin(), v.end(), xf);
    printf("%d\n", id + ego);
  }

  return 0;
}
