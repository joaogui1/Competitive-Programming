/*
ID: joaogui1
LANG: C++
TASK: numtri
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
int input[1010][1010], n, Max[1010][1010];
int main(){
   FILE *fin  = fopen ("numtri.in", "r");
   FILE *fout = fopen ("numtri.out", "w");
   int r;
   fscanf (fin, "%d", &r);

   for ( int i = 0; i < r; i++ )
      for ( int j = 0; j <= i; j++ ) fscanf (fin, "%d", &input [i][j]);

    for ( int i = r - 1; i >= 1; i-- )
      for ( int j = 0; j < i; j++ )
          input [i - 1][j] += max (input [i][j], input [i][j + 1]);

   fprintf (fout, "%d\n", input [0][0]);

   return 0;
}
