/*
ID: joaogui1
LANG: C++
TASK: combo
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
bool G[110][110][110];
int n;
int Val(int x){
	if(x > n)	return x%n;
	if(x < 1)	return n + x;
	return x;
}
int main(){
	int  a, b, c, x, y, z, ans = 0;
	ifstream fin ("combo.in");
    ofstream fout ("combo.out");
    fin >> n;
    fin >> a >> b >> c;
    fin >> x >> y >> z;
    //cout << n << " " << a << " " << b << " " << c << " " << x << " " << y << " " << z << endl;
    for(int i = -2; i < 3; ++i)
		for(int j = -2; j < 3; ++j)
			for(int k = -2; k < 3; ++k){
				//cout << Val(a + i) << " " << Val(b + j) << " " << Val(c + k) << endl;
				if(!G[Val(a + i)][Val(b + j)][Val(c + k)]){
					++G[Val(a + i)][Val(b + j)][Val(c + k)];
					++ans;
				}
				if(!G[Val(x + i)][Val(y + j)][Val(z + k)]){
					++G[Val(x + i)][Val(y + j)][Val(z + k)];
					++ans;
				}
			}
	if(n == 1) fout << 1 << endl;
	else	fout << ans << endl;

	return 0;
}
