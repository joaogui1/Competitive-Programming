/*
ID: joaogui1
LANG: C++
TASK: dualpal
*/
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
string convert(int n, int b){
    int x = 1, p = 0;
    string ret;
    while(n >= x){
        x *= b;
        ++p;
    }
    for(int i = 0; i < p; ++i)  ret +='*';
    for(int i = 1; i <= p; ++i){
        if(n % b < 10)  ret[p - i] = '0' + n % b;
        else ret[p - i] = 'A' + n % b - 10;
        n /= b;
    }
    return ret;
}
bool palindrome(string s){
    bool vdc = 1;
    int siz = s.size();
    for(int i = 0; i < siz; ++i){
        if(s[i] != s[siz - i - 1]) vdc = 0;
    }

    return vdc;
}
int main(){
    int n, s, cont = 0;
    string aux_s;
    ifstream fin ("dualpal.in");
    ofstream fout ("dualpal.out");
    fin >> n;
    fin >> s;s++;
    while(n > 0){
        cont = 0;
        for(int i = 2; i < 11 && cont != 2; ++i){
            if(palindrome(convert(s, i)))   cont++;
        }
        if(cont == 2){
           fout << s << endl;
           --n;
        }
        ++s;
    }

    return 0;
}
