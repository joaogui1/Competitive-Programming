#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int cnt[100100];
vector<int> adj[100100];
int u[100100], v[100100];
int dfn[100100], anc[17][100100], lvl[100100], temp;

bool comp(int a, int b){
	return dfn[a] < dfn[b];
}

void dfs(int s, int p){
	int w;
	dfn[s] = ++temp;
	for(int i = 0; i < adj[s].size(); ++i){
		w = adj[s][i];
		if(w != p){
			lvl[w] = lvl[s] + 1;
			anc[0][w] = s;
			dfs(w, s);
		}
	}
}

int lca(int s, int e){
	if(lvl[s] < lvl[e]) swap(s, e);
	int aux = lvl[s] - lvl[e];
	for(int i = 0; i < 17; ++i){
		if((aux >> i) & 1) s = anc[i][s];
	}
	for(int i = 16; i >= 0; --i){
		if(anc[i][s] != anc[i][e]){
			s = anc[i][s];
			e = anc[i][e];
		}
	}
	if(s == e) return s;
	return anc[0][s];
}

void upd(int s, int e){
	++cnt[s];
	++cnt[e];
	cnt[lca(s, e)] -= 2;
}

void f(int s, int p){
	int w;
	for(int i = 0; i < adj[s].size(); ++i){
		w = adj[s][i];
		if(w != p){
			f(w, s);
			cnt[s] += cnt[w];
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m, k, t;
	cin >> n >> m >> k;
	for(int i = 0; i < n - 1; ++i){
		cin >> u[i] >> v[i];
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
	}

	dfs(1, -1);

	for(int i = 1; i < 17; ++i)
		for(int j = 1; j <= n; ++j)
			anc[i][j] = anc[i-1][anc[i-1][j]];


	for(int i = 0; i < m; ++i){
		cin >> t;
		vector<int> vec(t);
		for(int j = 0; j < t; ++j)
			cin >> vec[j];
		sort(vec.begin(), vec.end(), comp);
		for(int i = 0; i < vec.size(); ++i){
			upd(vec[i], vec[(i+1) % vec.size()]);
		}
	}

	f(1, -1);

	vector<int> vec;
	for(int i = 0; i < n - 1; ++i){
		if(dfn[u[i]] > dfn[v[i]]) swap(u[i], v[i]);
		if(cnt[v[i]] >= 2*k) vec.push_back(i+1);
	}
	cout << vec.size() << "\n";
	for(int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " \n"[i + 1 == vec.size()];
}
