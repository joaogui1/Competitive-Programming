/*
ID: joaogui1
LANG: C++
TASK: frac1
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
vector <pair <int, int> > fracs;
bool comp(pair <int, int> a, pair<int, int> b){
   if(a.first*b.second != a.second*b.first)return (a.first*b.second < a.second*b.first);
   return a.first < b.first;
}
bool eq(pair <int, int> a, pair<int, int> b){
   return a.first*b.second == a.second*b.first;
}
int main(){
   int n,  sz;
   pair <int, int> aux = make_pair(-1, 1);
   ifstream fin ("frac1.in");
   ofstream fout ("frac1.out");
   fin >> n;
   for(int j = 1; j <= n; ++j)
      for(int i = j - 1; i > 0; --i)
         fracs.push_back(make_pair(i, j));
   fracs.push_back(make_pair(1, 1));
   fracs.push_back(make_pair(0, 1));
   sz = fracs.size();
   sort(fracs.begin(), fracs.end(), comp);
   for(int i = 0; i < sz; ++i)
      if(!eq(fracs[i], aux)){
         fout << fracs[i].first << "/" << fracs[i].second << endl;
         aux = fracs[i];
      }


   return 0;
}
