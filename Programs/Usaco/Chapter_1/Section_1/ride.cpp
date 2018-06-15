/*
ID: joaogui1
LANG: C++
TASK: ride
*/
#include <cstdio>
#include <cstring>
char UFO[18], G[18];
main () {
    int a = 1, b = 1, aux;
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    fscanf (fin, "%s %s", UFO, G);
    aux = strlen(UFO);
    for(int i = 0; i < aux; ++i)
        a*=(int)(UFO[i] -'A' + 1);
    aux = strlen(G);
    for(int i = 0; i < aux; ++i)
        b*=(int)(G[i] - 'A' + 1);

    if(b%47 == a%47)
        fprintf (fout, "GO\n");
    else
        fprintf (fout, "STAY\n");

    return 0;
}
