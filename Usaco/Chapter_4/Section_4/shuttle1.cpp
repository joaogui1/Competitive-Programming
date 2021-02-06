/*
ID: joaogui1
LANG: C++
TASK: shuttle
*/
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
int n, way[100005], num = -1;
string ini, fim;

bool dfs(int x){
   way[++num] = x;
   if(ini == fim) return true;

   if(x > 2 && ini[x - 1] == 'B' && ini[x - 2] == 'W'){
      swap(ini[x], ini[x - 2]);
      if(dfs(x - 2)) return true;
      swap(ini[x], ini[x - 2]);
   }

   if(x > 1 && ini[x - 1] == 'W'){
      swap(ini[x], ini[x - 1]);
      if(dfs(x - 1)) return true;
      swap(ini[x], ini[x - 1]);
   }

   if(x < 2*n + 1 && ini[x + 1] == 'B'){
      swap(ini[x], ini[x + 1]);
      if(dfs(x + 1)) return true;
      swap(ini[x], ini[x + 1]);
   }

   if(x < 2*n && ini[x + 1] == 'W' && ini[x + 2] == 'B'){
      swap(ini[x], ini[x + 2]);
      if(dfs(x + 2)) return true;
      swap(ini[x], ini[x + 2]);
   }
   num--;
   return false;
}

int main(){
   ios_base::sync_with_stdio(0);
   ifstream fin ("shuttle.in");
   ofstream fout ("shuttle.out");
   fin >> n;
   //fin.close();
   ini = " ";
   fim = " ";
   for(int i = 0; i != n; ++i)   ini +='W';
   ini += ' ';
   for(int i = 0; i != n; ++i)   ini += 'B';

   for(int i = 0; i != n; ++i)   fim +='B';
   fim += ' ';
   for(int i = 0; i != n; ++i)   fim += 'W';
   //num = -1;
   dfs(n + 1);
   fout << way[1];
   //cout << num << endl;
   for(int i = 2; i <= num; ++i){
      if(i %20 == 1) fout << "\n" << way[i];
      else  fout << " " << way[i];
   }
   fout <<"\n";
   fin.close();fout.close();
   return 0;
}
