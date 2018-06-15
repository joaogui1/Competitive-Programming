/*
ID: joaogui1
LANG: C++
TASK: palsquare
*/
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
int power[15];

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
    int b, cont = 0 , aux;
    string aux_s;
    ifstream fin ("palsquare.in");
    ofstream fout ("palsquare.out");
    fin >> b;
    for(int i = 1; i <= 300; ++i){
        aux_s = convert(i*i, b);
        if(palindrome(aux_s)) fout << convert(i, b) << " " << aux_s << endl;
    }

    return 0;
}
