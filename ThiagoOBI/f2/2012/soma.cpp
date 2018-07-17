#include <bits/stdc++.h>

using namespace std;

vector <int> v;

int main(){
  int n, k;
  vector<int>::iterator it;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &k);
    v.push_back(k);
  }
  scanf("%d", &k);
  for(int i = 0; i < n; ++i){
    it = lower_bound(v.begin(), v.end(), k - v[i]);
    if(*it == k - v[i]){
      printf("%d %d\n", v[i], (*it));
      break;
    }
  }




  return 0;
}
