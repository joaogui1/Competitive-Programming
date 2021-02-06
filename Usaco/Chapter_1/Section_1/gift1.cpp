/*
ID: joaogui1
LANG: C++
TASK: gift1
*/
#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
map <string, int> mapa;
vector <string> v;
main () {
    int aux, gift, n;
    string aux_str;
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");
    fin >> n;

    for(int i = 0; i < n; ++i){
        fin >> aux_str;
        mapa.insert(pair<string, int>(aux_str, 0));
        v.push_back(aux_str);
    }
    for(int i = 0; i < n; ++i){
        fin >> aux_str >> aux;
        mapa[aux_str] -= aux;
        gift = aux;
        fin >> aux;
        if (aux != 0){
            mapa[aux_str] += gift % aux;
            gift /= aux;
        }
        for (int i = 0; i < aux; ++i){
            fin >> aux_str;
            mapa[aux_str] += gift;
        }
    }
    aux = v.size();
    for(int i = 0; i < aux; ++i){
        fout << v[i] << " " <<mapa[v[i]] <<endl;
    }


    return 0;
}
