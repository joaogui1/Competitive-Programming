#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int n;
int val[100000];
int best[100010];
int sum[100010];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &val[i]);
	}
	sum[0] = 0;
	best[0] = 0;
	for (int i = 0; i < n; i++) {
		sum[i+1] = sum[i] + val[i];
		best[i+1] = max(best[i], sum[i+1]); //melhor entre sair adicionando os caras ou nao
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = max(ans, best[i] + (sum[n] - sum[i])); //a pizza eh circular
	}
	int tmp = 0;
	for (int i = 0; i < n; i++) { //kadane
		tmp = max(0, tmp + val[i]);
		ans = max(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}
