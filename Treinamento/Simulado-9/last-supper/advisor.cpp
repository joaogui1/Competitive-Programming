#include "advisor.h"
#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

set<pii> s;
vector <pii> tims;
int sca[100100], in[100100], rem[100100], rem_req[100100], rem_sca[100100];

int nextuse(int x, int t){
  auto it = lower_bound(tims.begin(), tims.end(), pii(x, t));
  if(it -> ff != x)  return 1000000;
  else return it -> ss;
}

void ComputeAdvice(int *C, int N, int K, int M){
  vector <int> aux;
  for(int i = 0; i < N; ++i)  tims.push_back(pii(C[i], i));
  sort(tims.begin(), tims.end());

  for(int i = 0; i < K; ++i) s.insert(pii(nextuse(C[i], -1), C[i])), sca[i] = i, in[i] = 1;
  for(int i = 0; i < N; ++i){
    rem_req[i] = -1;
    if(in[C[i]]){
      if(s.find(pii(i, C[i])) != s.end())  s.erase(pii(nextuse(C[i], i), C[i]));
      s.insert(pii(nextuse(C[i], i), C[i]));
    }
    else{
      auto it = s.end();
      --it;
      rem[i] = it -> ss;
      in[C[i]] = 1;
      in[it -> ss] = 0;
      s.erase(it);
      s.insert(pii(nextuse(C[i], i), C[i]));
    }
  }

  for(int i = 0; i < N; ++i){
    if(rem[i] != -1){
      auto it = lower_bound(tims.begin(), tims.end(), pii(rem[i], i));
      if(it == tims.begin() || (it - 1) -> ff != rem[i]){
        rem_sca[rem[i]] = 1;
      }
      else{
        --it;
        rem_req[it -> ss] = 1;
      }
    }
  }
  cout <<"ok\n";
  for(int i = 0; i < N; ++i)
      WriteAdvice(rem_req[i]);


  for(int i = 0; i < K; ++i)
    WriteAdvice(rem_sca[i]);

}
