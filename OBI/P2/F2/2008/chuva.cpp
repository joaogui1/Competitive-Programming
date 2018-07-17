#include <set>
#include <cstdio>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
#define SET(obj, x) memset(obj, x, sizeof(obj))
#define INF 0x3f3f3f3f
int x1[3010], y1[3010], x2[3010], y2[3010];
int cost[3010][3010], dist[3010], mark[3010];
struct index_lt {
	bool operator ()(const int a, const int b) const {
		if (int t = dist[a] - dist[b]) return t < 0;
		return a < b;
	}
};
set<int, index_lt> heap;
using namespace std;
int main(){
  int n, xi, yi, xf, yf;
	scanf("%d %d %d %d", &xi, &yi, &xf, &yf);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]); //os pontos cobertos sao nos
	}
	x1[n] = x2[n] = xi; y1[n] = y2[n] = yi; //o comeco eh no
	x1[n + 1] = x2[n + 1] = xf; y1[n + 1] = y2[n + 1] = yf; //o fim e no
	SET(cost, INF);
	for(int i = 0; i < n + 2; i++) {
		for(int j = 0; j < n + 2; j++) {
			int dx = max(0, max(x1[i], x1[j]) - min(x2[i], x2[j]));
			int dy = max(0, max(y1[i], y1[j]) - min(y2[i], y2[j]));
			cost[i][j] = dx + dy;
		}
	}
	cout << cost[0][1] << "\n";
	SET(dist, INF);
	dist[n] = 0;
	heap.insert(n);
	while(!heap.empty()){
      int ndist;
		int davez = *heap.begin();heap.erase(davez);
		mark[davez] = 1;
		for(int i = 0; i < n + 2; ++i) {
			if(mark[i]) continue;
			ndist = dist[davez] + cost[davez][i];
			if(ndist < dist[i]) {
				// if(i == 1){
        //   cout << ndist << " " << cost[davez][i] << "\n";
        // }
				heap.erase(i);
				dist[i] = ndist;
				heap.insert(i);
			}
		}
	}
	printf("%d\n", dist[n + 1]);
	return 0;
}
