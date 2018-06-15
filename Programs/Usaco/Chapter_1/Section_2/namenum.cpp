/*
ID: joaogui1
LANG: C++
TASK: namenum
*/
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
using namespace std;
int num[20], s, n,loop[20];
bool vdc = 0;
map <char, int> m;
string aux, dicts[5000];
ifstream fin ("namenum.in");
ofstream fout ("namenum.out");
ifstream dict ("dict.txt");


void initialize(){ //ok
    m['A'] = 2, m['B'] = 2, m['C'] = 2, m['D'] = 3, m['E'] = 3, m['F'] = 3, m['G'] = 4, m['H'] = 4, m['I'] = 4, m['J'] = 5, m['K'] = 5;
    m['L'] = 5, m['M'] = 6, m['N'] = 6, m['O'] = 6, m['P'] = 7, m['R'] = 7, m['S'] = 7, m['T'] = 8, m['U'] = 8, m['V'] = 8, m['W'] = 9, m['X'] = 9, m['Y'] = 9;
    char aux_c;
    int i = 0;
    while(fin >> aux_c)
        num[++i] = aux_c - '0';
    s = i;
    i = 1;
    while(dict >> dicts[i]){
        ++i;
    }
    n = i;
}

void loops(){
    int j = 0;
    for(int i = 1; i <= n; ++i){
        if(dicts[i].size() == s){
            for(j = 0; j < s; ++j){
                if(m[dicts[i][j]] != num[j + 1])    break;
            }
            if(j == s){
                fout << dicts[i] << endl;
                vdc = 1;
            }
        }

    }
    return;

}

int main(){
    initialize();
    loops();
    if(!vdc)    fout << "NONE" << endl;
    return 0;
}
