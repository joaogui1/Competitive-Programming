/*
ID: joaogui1
LANG: C++
TASK: milk2
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct farmer{
    int x;
    int y;
};
bool comp(farmer a, farmer b){
    if(a.x != b.x)  return a.x < b.x;
    return a.y < b.y;
}
farmer v[5100];
int main(){
    int cont = 0, gap = 0, beg = 0, end = 0, n, aux_int1, aux_int2;
    FILE *fin  = fopen ("milk2.in", "r");
    FILE *fout = fopen ("milk2.out", "w");
    fscanf(fin, "%d", &n);
    for(int i = 1; i <= n; ++i) fscanf(fin, "%d %d", &v[i].x, &v[i].y);
    sort(v + 1, v + n + 1, comp);
    for(int i = 1; i <= n; ++i){
        aux_int1 = v[i].x; aux_int2 = v[i].y;
        if(aux_int1 > end){
            if(aux_int1 - end > gap && i != 1)    gap = aux_int1 - end;
            beg = aux_int1;
        }
        if(end < aux_int2)  end = aux_int2;
        if(end - beg > cont)    cont = end - beg;
    }
    fprintf(fout ,"%d %d\n", cont, gap);

    return 0;
}
