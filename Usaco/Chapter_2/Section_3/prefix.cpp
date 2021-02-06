/*
ID: joaogui1
LANG: C++
TASK: prefix
*/
#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
#define max(a, b) a>b?a:b
using namespace std;

string input , aux, primitives[205];
int ans, primitivesSize[205], num = 0;
bool isAvailable[200100];

int main (){
   int len;
   ifstream fin ("prefix.in");
   ofstream fout ("prefix.out");
   while (1) {
        fin >> aux;
        if(aux == ".")  break;
        primitives[num] = aux;
        primitivesSize[num++] = aux.size();
    }
    while (fin >> aux)  input += aux;
    isAvailable [0] = true;
    len = input.size();
    for(int i = 0; i < len; i++) {
        if(isAvailable[i]) {
            for ( int j = 0; j < num;j++) {
                if (input.compare(i, primitivesSize[j], primitives[j]) == 0) {
                    ans = max(ans, i + primitivesSize[j]);
                    isAvailable[i + primitivesSize[j]] = 1;
                }
            }
        }
    }

    fout << ans << endl;

    return 0;
}
