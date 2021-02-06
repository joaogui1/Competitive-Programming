#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

int susc[110000];
int vac[110000];
int proc[110000];
int inc[110000];
vector<int> leaf;
vector<int> adj[110000];
vector<int> contamina[110000];
int n, ans = 0;

void contaminar(int curr, int t) {
	for (int vizinho : adj[curr]) if (!proc[vizinho]) {
		contamina[vizinho].push_back(t+1);
		if (--inc[vizinho] == 1) leaf.push_back(vizinho);
	}
	ans++;
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &susc[i]);
		scanf("%d", &vac[i]);
	}

	for (int i = 0; i < n-1; i++) {
		int u, v;
		scanf("%d %d", &u, &v); u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u); 
		inc[u]++;
		inc[v]++;
	}

	for (int i = 0; i < n; i++) if (adj[i].size() == 1) leaf.push_back(i);

	while (!leaf.empty()) {
		int curr = leaf[leaf.size()-1];
		leaf.pop_back();
		proc[curr]=1;
		
		bool ok = false;
		
		if (vac[curr] == 0) {
			contaminar(curr, 0);
			ok = true;
		}

		if (!ok && contamina[curr].size() >= susc[curr]) {
			nth_element(contamina[curr].begin(), contamina[curr].begin()+(susc[curr]-1), contamina[curr].end());
			if (contamina[curr][susc[curr]-1] <= vac[curr]) {
				contaminar(curr, contamina[curr][susc[curr]-1]);
				ans--;
				ok = true;
			} 
		}

		if (!ok && contamina[curr].size() >= susc[curr]-1 && inc[curr]) {
			if (susc[curr] != 1) {
				nth_element(contamina[curr].begin(), contamina[curr].begin()+(susc[curr]-2), contamina[curr].end());
			}
			if (susc[curr] == 1 || contamina[curr][susc[curr]-2] <= vac[curr]) {
				for (int vizinho : adj[curr]) if (!proc[vizinho]) {
					vac[vizinho] = min(vac[vizinho], vac[curr]-1);
					if (--inc[vizinho] == 1) leaf.push_back(vizinho);
				}
				ok = true;
			}
		}

		if (!ok) {
			contaminar(curr, 0);
		}
	}

	printf("%d\n", ans);
}