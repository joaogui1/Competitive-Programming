/*
ID: joaogui1
LANG: C++
TASK: milk
*/
#include <cstdio>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
pair <int, int> farmers[5010];
int main(){
	int n, m, i, p = 0;
	FILE *fin  = fopen ("milk.in", "r");
    FILE *fout = fopen ("milk.out", "w");
	fscanf(fin, "%d %d", &n, &m);
	for(i = 0; i < m; ++i)	fscanf(fin,"%d %d", &farmers[i].first, &farmers[i].second);
	sort(farmers, farmers + m);
	//for(i = 0; i < m; ++i)	cout << farmers[i].first << " " << farmers[i].second << endl;
	i = 0;
	while(n > 0){
		if(n < farmers[i].second){
			p += n*farmers[i].first;
			n = 0;
		}
		else{
			n -= farmers[i].second;
			p += (farmers[i].second*farmers[i++].first);
		}

	}
	fprintf(fout, "%d\n", p); 
	return 0;
}
