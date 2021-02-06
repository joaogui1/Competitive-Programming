int lcs[2][1000];

int make_lcs(string a, string b) {
  int na = a.size(), nb = b.size();
  lcs[0][0] = 0;
  for (int y = 0; y <= nb; ++y) lcs[0][y] = 0;
  for (int x = 0; x <= na; ++x) lcs[x%2][0] = 0;
  for (int x = 1; x <= na; ++x)
    for (int y = 1; y <= nb; ++y) {
      lcs[x%2][y] = max(lcs[(x-1)%2][y], max(lcs[x%2][y-1], lcs[(x-1)%2][y-1] + (a[x-1] == b[y-1])));
    }
}



int _dp[2][100+100+1];
int &dp(int i, int v) { return _dp[i%2][v + 100]; }

int main() {
  for (int i = 0; i < n; ++i) {
    for (int v = -100; v <= 100; ++v) {
      dp(i, v) = dp(i-1, 100-v);
    }
  }

  return 0;
}
