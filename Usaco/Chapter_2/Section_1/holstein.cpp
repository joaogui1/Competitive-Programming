/*
ID: joaogui1
LANG: C++
TASK: holstein
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
#define F(x) for(x = 0; x < 2; ++x)
using namespace std;
int req[35], food[35][35], aux_v[35], v, g, teste = 0;
vector <int> vec;
bool eq(){
   for(int i = 0; i < v; ++i)
      if(aux_v[i] < req[i])   return 0;
   return 1;
}
bool is_enough(int x){
   for(int i = 0; i < g; ++i)
      if(x & 1 << i){
         for(int j = 0; j < v; ++j)
            aux_v[j] += food[j][i];
         }
   bool ret = eq();
   for(int j = 0; j < v; ++j) aux_v[j] = 0;
   return ret;
}
int size(int x){
   int ret = 0;
   for(int i = 0; i < g; ++i){
      if(x & 1 << i) ++ret;
   }
   return ret;
}
int val(int x){
   int ret = 0;
   for(int i = 0; i < v; ++i)
      if(x & 1 << i) ret += i;
   return ret;

}
int main(){
   int ans, aux = 0, ans_size = 30, ans_val = 25*13, sz, val_i;
   ifstream fin ("holstein.in");
   ofstream fout ("holstein.out");
   fin >> v;
   for(int i = 0; i < v; ++i)
      fin >> req[i];
   fin >> g;
   for(int i = 0; i < g; ++i)
      for(int j = 0; j < v; ++j)
         fin >> food[j][i];
   for(int i = 1; i < 1 << g; ++i){
      if(is_enough(i)){
         sz = size(i), val_i = val(i);
         if(sz < ans_size || (sz == ans_size && val_i < ans_val)){
            ans = i;
            ans_size = sz;
            ans_val = val_i;
         }
      }
   }
   fout << ans_size << " ";
   for(int i = 0; i < g ; ++i)
      if(ans & 1 << i) vec.push_back(i + 1);
   for(int i = 0; i < vec.size() - 1; ++i)
      fout << vec[i]<< " ";
   fout << vec[vec.size() - 1] << endl;
   return 0;
}
