#include <algorithm>
#include <vector>
#include <cstdio>

#define INF 1000000000

using namespace std;

vector<int> lis(vector<int> V) {
  int n = V.size();

  vector<int> prev(n, -1);
  
  vector<int> L(n+1, INF);
  L[0] = -INF;
  vector<int> pos(n+1, -1);

  for (int i = 0; i < n; ++i) {
    int v = V[i];

    int kplus1 = lower_bound(L.begin(), L.end(), v)-L.begin(); // L[k+1] >= v
    int k = kplus1 - 1; // L[k] < v

    L[k+1] = v;
    pos[k+1] = i;

    prev[i] = pos[k];
  }

  int max_size = lower_bound(L.begin(), L.end(), INF) - L.begin() - 1;
  int last = pos[max_size];
  vector<int> ret;
  while (last != -1) {
    ret.push_back(last);
    last = prev[last];
  }
  reverse(ret.begin(), ret.end());

  return ret;
}

int main() {
  //  vector<int> v = {2, 0, 1, 3, 2, 4, 1, 2, 5, 4, 6};
  vector<int> v = {};
  vector<int> ret = lis(v);

  printf("Lis(positions):");
  for (int i = 0; i < (int)ret.size(); ++i)
    printf(" %d", ret[i]);
  printf("\n");

    printf("Lis(values):");
  for (int i = 0; i < (int)ret.size(); ++i)
    printf(" %d", v[ret[i]]);
  printf("\n");

  return 0;
}
