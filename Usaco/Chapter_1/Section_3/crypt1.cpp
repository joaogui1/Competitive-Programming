/*
ID: joaogui1
LANG: C++
TASK: crypt1
*/
#include <set>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
int nums[19];
set <int> comb[10];
void initialize(int n){
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
				for(int k = 0; k < n; ++k)	comb[3].insert(nums[i]*100 + nums[j]*10 + nums[k]);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
				for(int k = 0; k < n; ++k)
					for(int l = 0; l < n; ++l)	comb[4].insert(nums[i]*1000 + nums[j]*100 + nums[k]*10 + nums[l]);
	return;
}
int main(){
	int n, ans = 0;
	ifstream fin ("crypt1.in");
    ofstream fout ("crypt1.out");
	fin >> n;
	for(int i = 0; i < n; ++i)	fin >> nums[i];
	initialize(n);
	for(int a = 0; a < n; ++a)
		for(int b = 0; b < n; ++b)
			for(int c = 0; c < n; ++c)
				for(int d = 0; d < n; ++d)
					for(int e = 0; e < n; ++e){
							int abc = 100*nums[a] + 10*nums[b] + nums[c];
							int de = 10*nums[d] + nums[e];
							if(comb[3].count(nums[e]*abc) && comb[3].count(nums[d]*abc) && comb[4].count(abc * de))	++ans;
					}
	fout << ans << '\n';
	return 0;
}
