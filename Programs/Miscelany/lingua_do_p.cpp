#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1010
#define MAXM 5010
using namespace std;
int main(){
    string palavras;
    int i = 1, j = 1;
    getline(cin, palavras);
    j = palavras.size();
    for(int i = 1; i < j; ++i){
        if(palavras[i] == 'p' && palavras[i - 1] == ' ')
            --i;
        printf("%c", palavras[i]);
        ++i;
    }
    printf("\n");
    return 0;
}

