#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vint;

vector <int> x, aux, ans;

vint build(vint v, int b){
  vint ret;
  ret.push_back(b);
  for(int idx = 0, i = ret[0]; 2*i + 1 < v.size(); i = ret[++idx]){
    ret.push_back(2*i + 1);
    if(2*i + 2 < v.size())  ret.push_back(2*i + 2);
  }
  for(int i = 0; i < ret.size(); ++i)  ret[i] = v[ret[i]];
  return ret;
}

vint merge(vint a, vint b, int c) {
	vint ret;
	ret.push_back(c);
	int cnt = 1;
	for(int i = 0, j = 0; i < a.size() || j < b.size();){
		for (; i < a.size() && i < cnt; ++i)  ret.push_back(a[i]);
		for (; j < b.size() && j < cnt; ++j)  ret.push_back(b[j]);
		cnt = 2*cnt + 1;
	}
	return ret;
}

vint f(vint a){
  if(a.size() < 2)  return a;
  if(a.size() == 2){
    if(a[0] > a[1]) swap(a[0], a[1]);
    return a;
  }
  vint aux1, aux2, ret;
  if(a[0] < a[1] && a[0] < a[2]){
    aux1 = build(a, 1);
    aux2 = build(a, 2);
    return merge(f(aux1), f(aux2), a[0]);
  }
  else if(a[1] < a[2]){
    swap(a[0], a[1]);
    aux1 = build(a, 1);
    aux2 = build(a, 2);
    return merge(f(aux1), f(aux2), a[0]);
  }

  swap(a[0], a[2]);
  aux1 = build(a, 1);
  aux2 = build(a, 2);
  ret = merge(f(aux1), f(aux2), a[0]);
  swap(a[1], a[2]);
  aux1 = build(a, 1);
  aux2 = build(a, 2);

  return min(ret, merge(f(aux1), f(aux2), a[0]));
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, resp;
  cin >> n;
  x.resize(n);
  for(int i = 0; i < n; ++i)  cin >> x[i];
  aux = build(x, 1);
  for(int j = 0; j < aux.size(); ++j) cout << aux[j] << " \n"[j + 1 == aux.size()];
  aux = build(x, 2);
  for(int j = 0; j < aux.size(); ++j) cout << aux[j] << " \n"[j + 1 == aux.size()];

  ans = f(x);
  for(int j = 0; j < ans.size(); ++j) cout << ans[j] << " \n"[j + 1 == n];

  return 0;
}
