#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair <int, int> pii;
typedef pair <pii, int> iii;

int n, pos[100100], p[100100];
ll ft[100100], ans[100100];

void update(int x){
	for(; x <= n; x += x&-x) ++ft[x];
}

ll query(int x){
	ll ans = 0;
  for(; x > 0; x -= x&-x) ans += ft[x];
	return ans;
}

ll query(int a, int b){
  return query(b) - query(a - 1);
}

ll query(pii a){
  return query(a.ff, a.ss);
}

bool comp(iii a, iii b){
	return a.ff.ss < b.ff.ss;
}


int main(){
  ios_base::sync_with_stdio(0);

	int m,d;
	cin >> n >> m >> d;
	for(int i = 1;i <= n; ++i){
		cin >> p[i];
		pos[p[i]] = i;
	}

	vector<iii> q;
	int l, r, ind;
	for(int i = 0; i < m; ++i){
		cin >> l >> r;
		q.push_back(iii(pii(l,r), i));
	}
	sort(q.begin(), q.end(), comp);

  int j = 0;
	for(int i = 1;i <= n; ++i){
		for(int k = max(1, p[i] - d); k <= min(n, p[i] + d); ++k)
			if(pos[k] <= i)
				update(pos[k]);


		for(; j < q.size() && q[j].ff.ss == i; ++j)
			ans[q[j].ss] = query(q[j].ff);

	}

	for(int i = 0; i < m; ++i)
		cout << ans[i] << "\n";

}
