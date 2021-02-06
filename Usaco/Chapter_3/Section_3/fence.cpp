/*
ID: joaogui1
LANG: C++
TASK: fence
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
int adj[(1 << 10) + 10][(1 << 10) + 10];
int circuit[1 << 9], circuit_pos, f;

void find_circuit(int x){
   if(!adj[x][0]);
   else  for(int i = 1; i <= 500; ++i)
      if(adj[x][i]){
         --adj[x][i];--adj[i][x];
         --adj[x][0];--adj[i][0];
         find_circuit(i);
      }
   circuit[circuit_pos++] = x;
   return;
}

int main(){
   ios_base::sync_with_stdio(0);
   int a, b;
   ifstream fin ("fence.in");
   ofstream fout ("fence.out");
   fin >> f;
   for(int i = 0; i < f; ++i){
      fin >> a >> b;
      ++adj[a][b];++adj[b][a];
      ++adj[a][0], ++adj[b][0];
   }
   for(int i = 1; i < 501; ++i){
      if(adj[i][0]%2){
         find_circuit(i);
         break;
      }
      if(i == 500)   find_circuit(1);
   }
   for(int i = circuit_pos - 1; i >= 0; --i) fout << circuit[i] << "\n";
   return 0;
}
