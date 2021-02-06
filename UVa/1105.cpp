#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#define debug(a, b, c, d ,e)  std::cout << a << " " << b << " " << c << " " << d << " " << e
#define INF (1 << 30)
#define SET(obj, a) memset(obj, a, sizeof(obj))
#define LSOne(x) (x & (-x))
#define MAXVALUE 1 << 10
using namespace std;
int city[2020][2020], m[30];
void rotate(int x, int y, int &tx, int &ty, int dx, int dy) { //rotate 45 degrees
	tx = x - y + dy, ty = x + y;
}
void query(int m, int dx, int dy) {
	int ret = 0, ret_x = 1, ret_y = 1;
	int tx, ty;
	for (int j = 1; j <= dy; j++) {
		for (int i = 1; i <= dx; i++) {
			rotate(i, j, tx, ty, dx, dy);
			int lx, rx, ly, ry, cnt;
			lx = max(tx - m, 1);
			ly = max(ty - m, 1);
			rx = min(tx + m, dx + dy);
			ry = min(ty + m, dx + dy);
			cnt = city[rx][ry] - city[rx][ly-1] - city[lx-1][ry] + city[lx-1][ly-1];
			if (cnt > ret) {
				ret = cnt, ret_x = i, ret_y = j;
			}
		}
	}
	printf("%d (%d,%d)\n", ret, ret_x, ret_y);
}
int main(){
   int dx, dy, n, q;
	int x, y, tx, ty, limit, cases = 0;
	while (scanf("%d %d %d %d", &dx, &dy, &n, &q) == 4 && dx) {
		SET(city, 0);
		for (int i = 0; i < n; i++){
			scanf("%d %d", &x, &y);
			rotate(x, y, tx, ty, dx, dy);
			city[tx][ty]++;
		}

		for (int i = 1; i <= dx + dy; i++) {
			for (int j = 1, s = 0; j <= dx + dy; j++) {
				s += city[i][j];
				city[i][j] = city[i-1][j] + s;
			}
		}

		printf("Case %d:\n", ++cases);
		for (int i = 0; i < q; i++) {
			scanf("%d", &limit);
			query(limit, dx, dy);
		}
	}
	return 0;
}
