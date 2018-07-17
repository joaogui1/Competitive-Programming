/*
ID: joaogui1
LANG: C++
TASK: barn1
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
vector < pair <int, int > > cow;
vector <int> entrada;

int main(){
	int m, c, s, aux_i, ans = 0;
	ifstream fin ("barn1.in");
   ofstream fout ("barn1.out");
   while(fin >> aux_i)	entrada.push_back(aux_i);
	m = entrada[0];
	s = entrada[1];
	c = entrada[2];
	sort(entrada.begin() + 3, entrada.end());
	aux_i = entrada[3];
	cow.push_back(make_pair(999999, aux_i));
	for(int i = 1; i < c; ++i){
		aux_i = entrada[3 + i];
		cow.push_back(make_pair(aux_i - cow.back().second - 1, aux_i));
	}
	sort(cow.begin(), cow.end());
	ans = c;
	for(int cont = 0; cont < c-m; ++cont)	ans += cow[cont].first;
	fout << ans << endl;


	return 0;
}
