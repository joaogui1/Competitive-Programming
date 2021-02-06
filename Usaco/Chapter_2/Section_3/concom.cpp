/*
ID: joaogui1
LANG: C++
TASK: concom
*/
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
int mark[110][110],  stocks[110][110], owns[110][110];
vector < pair<int, int> > ans;
int main(){
   int n, i ,j ,p, comps = 0, aux, k;
   ifstream fin ("concom.in");
   ofstream fout ("concom.out");
   fin >> n;
   for(int k = 1; k <= n; ++k){
      fin >> i >> j >> p;
      stocks[i][j] = p;
      if(i > comps)  comps = i;
      if(j > comps)  comps = j;
   }
   for(i = 1; i < 101; i++){
        for(j = 1; j < 101; j++){
            if(i != j && !mark[i][j] && stocks[i][j] > 50){
                mark[i][j] = 1;
                for(k = 1; k < 101; k++){
                    stocks[i][k] += stocks[j][k];
                    if(mark[j][k]) mark[i][k] = 1;
                }
                j = 0;
            }
        }
    }
    for(i = 1; i < 101; i++){
        for(j = 1; j < 101; j++){
            if(i != j && mark[i][j]) fout << i << " " << j << endl;
        }
    }

   return 0;
}
