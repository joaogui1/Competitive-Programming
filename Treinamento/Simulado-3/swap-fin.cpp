#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vint;

int n;
map<int, int> dp[200100];
vector <int> x, aux, ans;

vint jmerge(vint &ret, vint a, vint b) {
	int cnt = 1;
	for(int i = 0, j = 0; i < a.size() || j < b.size();){
		for (; i < a.size() && i < cnt; ++i)  ret.push_back(a[i]);
		for (; j < b.size() && j < cnt; ++j)  ret.push_back(b[j]);
		cnt = 2*cnt + 1;
	}
	return ret;
}

int f(int pos, int val){
  if(pos > n) return -1;
  if(dp[pos].count(val) != 0) return dp[pos][val];
  cout << pos << " " << val << "\n";
  if(val < x[2*pos] && val < x[2*pos + 1]){
    f(2*pos, x[2*pos]);
    f(2*pos + 1, x[2*pos + 1]);
    return dp[pos][val] = val;
  }
  else if(x[2*pos] < x[2*pos + 1]){
    int ret = f(2*pos, val);
    f(2*pos + 1, x[2*pos + 1]);
    return dp[pos][val] = ret;
  }
  int aux[4];
  aux[0] = f(2*pos, x[2*pos]);
  aux[1] = f(2*pos + 1, val);
  aux[2] = f(2*pos, val);
  aux[3] = f(2*pos + 1, x[2*pos]);
  if(min(aux[0], aux[1]) < min(aux[2], aux[3])) return dp[pos][val] = aux[1];

  if(min(aux[0], aux[1]) > min(aux[2], aux[3])) return dp[pos][val] = aux[2];
  if(val < x[2*pos]){
    if(aux[1] < aux[2]) return dp[pos][val] = aux[1];
    else  return dp[pos][val] = aux[2];

  }
  else{
    if(aux[0] < aux[3]) return dp[pos][val] = aux[1];
    else  return dp[pos][val] = aux[2];
  }

}

vint backtrack(int pos, int val){
  vint ret;
  if(pos > n) return ret;
  if(val < x[2*pos] && val < x[2*pos + 1]){
    ret.push_back(val);
    jmerge(ret, backtrack(2*pos, x[2*pos]), backtrack(2*pos + 1, x[2*pos + 1]));
    return ret;
  }
  else if(x[2*pos] < x[2*pos + 1]){
    ret.push_back(x[2*pos]);
    jmerge(ret, backtrack(2*pos, val), backtrack(2*pos + 1, x[2*pos + 1]));
    return ret;
  }
  int aux[2];
  ret.push_back(x[2*pos + 1]);
  aux[0] = f(2*pos, val);
  aux[1] = f(2*pos + 1, val);
  if(dp[pos][val] == aux[0])
    return jmerge(ret, backtrack(2*pos, val), backtrack(2*pos + 1, x[2*pos]));

  else
    return jmerge(ret, backtrack(2*pos, x[2*pos]), backtrack(2*pos + 1, val));
}

int main(){
  // cin.tie(0);
  // ios_base::sync_with_stdio(0);
  int resp;
  cin >> n;
  x.resize(n);
  for(int i = 1; i <= n; ++i)  cin >> x[i];
  f(1, x[1]);
  cout << f(1, x[1]) << "\n";
  ans = backtrack(1, x[1]);
  for(int j = 0; j < ans.size(); ++j) cout << ans[j] << " \n"[j + 1 == n];

  return 0;
}
