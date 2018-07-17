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
ifstream fin ("inversions.in");
ofstream fout ("inversions.out");
#endif
long long int mergesort(int beg, int end){
  if(beg + 1 == end)  return 0;

  int m = (beg + end)/2;
  int j = m, k = beg;
  long long int ret = mergesort(beg, m) + mergesort(m, end);
  for(int i = beg; i < m; ++i){
    while(j < end && v[j] < v[i]){
      w[k++] = v[j++];
      ret += m - i;
    }
    w[k++] = v[i];
  }
  for(; j < end; ++j, ++k)  w[k] = v[j];
  for(int i = beg; i < end; ++i)  v[i] = w[i];
  return ret;
}

int main(){
  int n;
  fin >> n;
  for(int i = 1; i <= n; ++i) fin >> v[i];
  fout << mergesort(1, n + 1) << "\n";

  return 0;
}
