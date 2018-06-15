#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <stack>
#include <climits>

#define INF 1000000000

using namespace std;

typedef long long lint;

lint solve(vector<int> &h, RMQ& rmq, int a, int b) {
  if (a > b) return 0;
  lint result = 0;

  int minid = rmq.query(a, b)%((int)h.size());
  int toleft = minid-a+1;
  int toright = b-minid+1;

  result += (lint)toleft * toright * h[minid];

  result += solve(h, rmq, a, minid-1);
  result += solve(h, rmq, minid+1, b);

  return result;
}

lint solve(vector<int> &h) {
  int n = h.size();
  vector<lint> hpos;
  for (int i = 0; i < n; ++i)
    hpos.push_back((1000000000-h[i])*n + i);
  RMQ rmq(hpos);
  return solve(h, rmq, 0, n-1);
}


void solve(vector<int> &h) {
  int n = h.size();

  vector<pair<int, int> > vi;
  for (int i = 0; i < n; ++i)
    vi.push_back(make_pair(h[i], i));
  sort(vi.rbegin(), vi.rend());

  long long ret = 0;
  
  set<int> poset;
  poset.insert(-1);
  poset.insert(n);
  for (int i = 0; i < n; ++i) {
    int v = vi[i].first, pos = vi[i].second;
    set<int>::iterator it = poset.insert(pos).first;
    set<int>::iterator it2 = it, it3 = it;
    --it2, ++it3;

    int toleft = *it2 + 1;
    int toright = *it3 - 1;
    ret += (toright - pos + 1) * (pos - toleft + 1);
  }

}


void solve2(vector<int> &h) {
  int n = h.size();
  stack<pair<int, int> > q;

  for (int i = 0; i < n; ++i) {
    pair<int, int> vi = make_pair(h[i], i);
    while (!q.empty() && q.top() < vi)
      q.pop();
    int toleft;
    if (q.empty()) toleft = i+1;
    else toleft = i-q.top().second;

    q.push(vi);
  }

  while (!q.empty()) q.pop();
  for (int i = n-1; i >= 0; --i) {
    pair<int, int> vi = make_pair(h[i], i);
    while (!q.empty() && q.top() < vi)
      q.pop();
    int toright;
    if (q.empty()) toright = n-i;
    else toright = q.top().second-i;

    q.push(vi);
  }
}

int lg2down(int n) {
  return __builtin_clz(1) - __builtin_clz(n);
}

struct RMQ {
  vector<vector<lint> > rmq;
  RMQ(const vector<lint> &v) {
    int n = v.size();
    int lg = lg2down(n);
    rmq = vector<vector<lint> >(n, vector<lint>(lg+1));
    for (int i = 0; i < n; ++i)
      rmq[i][0] = v[i];
    for (int l = 1; l <= lg; ++l)
      for (int i = 0; i < n; ++i)
	if (i + (1<<l) <= n)
	  rmq[i][l] = min(rmq[i][l-1],
			  rmq[i + (1<<(l-1))][l-1]);
  }
  lint query(int a, int b) {
    if (a > b) return INF;
    int size = b-a+1, l = lg2down(size);
    return min(rmq[a][l], rmq[b-(1<<l)+1][l]);
  }
};
