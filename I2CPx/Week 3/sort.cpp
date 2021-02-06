#include <bits/stdc++.h>
#define ff first
#define ss second
// #define DEBUG 1
#ifdef DEBUG
  #define fin cin
  #define fout cout
#endif

using namespace std;
int v[100100], w[100100];
#ifndef DEBUG
ifstream fin ("sort.in");
ofstream fout ("sort.out");
#endif
void mergesort(int beg, int end){
  if(beg + 1 == end){
    fout << beg << " " << end - 1 << " " << v[beg] << " " << v[end - 1] << "\n";
    return;
  }
  int m = (beg + end)/2;
  mergesort(beg, m);
  mergesort(m, end);
  int i = beg, j = m, k = beg;
  while(i < m or j < end){
    if(j == end || (i < m && v[i] < v[j]))
      w[k++] = v[i++];
    else
      w[k++] = v[j++];
  }
  for(int i = beg; i < end; ++i)  v[i] = w[i];
  fout << beg << " " << end - 1 << " " << v[beg] << " " << v[end - 1] << "\n";
  return;
}

int main(){
  int n;
  fin >> n;
  for(int i = 1; i <= n; ++i) fin >> v[i];
  mergesort(1, n + 1);
  for(int i = 1; i <= n; ++i)
    fout << v[i] << " \n"[i == n];
  return 0;
}
