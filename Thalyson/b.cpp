#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ifstream fin ("input.txt");
  ofstream fout ("output.txt");
  int n, m;
  fin >> n >> m;
  if(n > m){
    for(int i = 0; i < m; ++i)  fout << "BG";
    for(int i = m; i < n; ++i)  fout << "B";
    fout << "\n";
  }
  else{
    for(int i = 0; i < n; ++i)  fout << "GB";
    for(int i = n; i < m; ++i)  fout << "G";
    fout << "\n";
  }


  return 0;
}
