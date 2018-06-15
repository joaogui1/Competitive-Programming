#include<cstdio>
#include<string>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
struct word{
    string pal;
    int tam;
};

bool comp(word a, word b){
    return a.tam > b.tam;
}
word g[60];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        cin >> g[i].pal;
        g[i].tam = g[i].pal.size();
        printf("%d\n", g[i].tam);
    }
    sort(g, g+n, comp);
    for(int i = 0; i < n; ++i){
        sort(g[i].pal.begin(), g[i].pal.end());
        cout << g[i].pal+"\n";
    }

    return 0;
}
