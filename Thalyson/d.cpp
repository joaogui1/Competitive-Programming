#include <bits/stdc++.h>

using namespace std;

vector <int> pos[5010];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ifstream fin ("input.txt");
  ofstream fout ("output.txt");
  int n, aux;
  bool vdc = 1;
  fin >> n;
  for(int i = 0; i < 2*n; ++i){
    fin >> aux;
    pos[aux].push_back(i + 1);
  }
  for(int i = 0; i < 5001; ++i){
    if(pos[i].size() % 2 != 0)  vdc = 0;
  }
  if(!vdc)  fout << "-1\n";
  else{
    for(int i = 0; i < 5001; ++i){
      for(int j = 0; j < pos[i].size(); j += 2)  fout << pos[i][j] << " " << pos[i][j + 1] << "\n";
    }
  }

  return 0;
}
