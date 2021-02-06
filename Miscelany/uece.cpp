#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
int nums[19];
int main(){
	int a = 0,b = 0, c = 0, d = 0;
	char aux;
	for(int i = 0; i < 60; ++i){
		cin >> aux;
		if(aux == 'A')	++a;
		if(aux == 'B') 	++b;
		if(aux == 'C')	++c;
		if(aux == 'D') 	++d;
	}
	cout << a << " " << b << " " << c << " " << d << endl;
		
	return 0;
}
