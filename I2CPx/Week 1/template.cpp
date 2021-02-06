#include <bits/stdc++.h>
#define ff first
#define ss second
//#define fin cin
//#define fout cout

using namespace std;
typedef pair<int, int> pii;

map <char, pii> mp;

int main(){
  ifstream fin("template.in");
  ofstream fout("template.out");
  string in, aus, tmp, anss;
  int w, h, mnd = 10000000, tst;
  fin >> w >> h;
  getline(fin, in);
  for(int i = 0; i < h; ++i){
    getline(fin, in);
    for(int j = 0; j < w; ++j)
      mp[in[j]] = pii(i, j);
  }
  getline(fin, in);
  for(int i = 0; i < 3; ++i){
    tmp = "";
    getline(fin, in);
    while(1){
      if(!(getline(fin, aus)) || aus.size() == 0)
        break;
      tmp += aus;
    }
    tst = 0;
    for(int i = 1; i < tmp.size(); ++i)
      tst += max(abs(mp[tmp[i]].ff - mp[tmp[i - 1]].ff), abs(mp[tmp[i]].ss - mp[tmp[i - 1]].ss));
    if(mnd > tst){
      mnd = tst;
      anss = in;
    }
  }
  fout << anss << "\n" << mnd << "\n";
  return 0;
}
