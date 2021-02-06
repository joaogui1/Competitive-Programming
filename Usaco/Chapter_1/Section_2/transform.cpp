/*
ID: joaogui1
LANG: C++
TASK: transform
*/
#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;
int n;
bool G[20][20], B[20][20], T[20][20];
void rotate_matG(){
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            G[n - i + 1][j] = T[j][i];
}
void rotate_matT(){
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            T[n - i + 1][j] = G[j][i];
}
void reflex_matG(){
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            G[n - j + 1][i] = T[j][i];
}
void reflex_matT(){
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            T[n - j + 1][i] = G[j][i];
}
int main(){
    int ans = 0;
    bool aux_b = 0;
    char aux_char;
    FILE *fin  = fopen ("transform.in", "r");
    FILE *fout = fopen ("transform.out", "w");
    fscanf(fin, "%d", &n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            fscanf(fin, " %c", &aux_char);
            if(aux_char == '@') G[j][i] = 1;
        }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            fscanf(fin, " %c", &aux_char);
            if(aux_char == '@') B[j][i] = 1;
        }
    rotate_matT();
    for(int i = 1; i <= n && ans == 0; ++i){
        for(int j = 1; j <= n; ++j){
            if(aux_b)   break;
            if(T[j][i] != B[j][i])  aux_b = 1;
        }
        if(aux_b)   break;
        if(i == n)  ans = 1;
    }
    aux_b = 0;
    rotate_matG();
    for(int i = 1; i <= n && ans == 0; ++i){
        for(int j = 1; j <= n; ++j){
            if(aux_b)   break;
            if(G[j][i] != B[j][i])  aux_b = 1;
        }
        if(aux_b)   break;
        if(i == n)  ans = 2;
    }
    aux_b = 0;
    rotate_matT();
    for(int i = 1; i <= n && ans == 0; ++i){
        for(int j = 1; j <= n; ++j){
            if(aux_b)   break;
            if(T[j][i] != B[j][i])  aux_b = 1;
        }
        if(aux_b)   break;
        if(i == n)  ans = 3;
    }
    aux_b = 0;
    rotate_matG();
    reflex_matT();
    for(int i = 1; i <= n && ans == 0; ++i){
        for(int j = 1; j <= n; ++j){
            if(aux_b)   break;
            if(T[j][i] != B[j][i])  aux_b = 1;
        }
        if(aux_b)   break;
        if(i == n)  ans = 4;
    }
    aux_b = 0;
    rotate_matG();
    for(int i = 1; i <= n && ans == 0; ++i){
        for(int j = 1; j <= n; ++j){
            if(aux_b)   break;
            if(G[j][i] != B[j][i])  aux_b = 1;
        }
        if(aux_b)   break;
        if(i == n)  ans = 5;
    }
    aux_b = 0;
    rotate_matT();
    for(int i = 1; i <= n && ans == 0; ++i){
        for(int j = 1; j <= n; ++j){
            if(aux_b)   break;
            if(T[j][i] != B[j][i])  aux_b = 1;
        }
        if(aux_b)   break;
        if(i == n)  ans = 5;
    }
    aux_b = 0;
    rotate_matG();
    for(int i = 1; i <= n && ans == 0; ++i){
        for(int j = 1; j <= n; ++j){
            if(aux_b)   break;
            if(G[j][i] != B[j][i])  aux_b = 1;
        }
        if(aux_b)   break;
        if(i == n)  ans = 5;
    }
    aux_b = 0;
    rotate_matT();
    reflex_matG();
    for(int i = 1; i <= n && ans == 0; ++i){
        for(int j = 1; j <= n; ++j){
            if(aux_b)   break;
            if(G[j][i] != B[j][i])  aux_b = 1;
        }
        if(aux_b)   break;
        if(i == n)  ans = 6;
    }
    if(ans == 0)    ans = 7;
    fprintf(fout, "%d\n", ans);


    return 0;
}


