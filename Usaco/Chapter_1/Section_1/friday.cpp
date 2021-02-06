/*
ID: joaogui1
LANG: C++
TASK: friday
*/
#include <cstdio>
#include <cstring>
int week[17];
main () {
    int a, aux = 0;
    ++week[0];
    bool leap;
    FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");
    fscanf (fin, "%d", &a);
    for(int i = 1900; i < 1900 + a; ++i){
        if(i % 4 ==0 && (i%100 != 0 || i%400 == 0)) leap = 1;
        else    leap = 0;
        for(int j = 1; j <= 12; ++j){
            if(j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
                aux += 31;

            if(j == 4 || j == 6 || j == 9 || j == 11)
                aux += 30;

            if(j == 2)
                if(leap)    aux += 29;
                else        aux += 28;

            aux %= 7;
            ++week[aux];
        }
    }
    --week[aux];
    for(int i = 0; i < 7; ++i){
        fprintf (fout, "%d", week[i]);
        if(i != 6)  fprintf (fout, " ", week[i]);
    }
    fprintf (fout, "\n");

    return 0;
}
