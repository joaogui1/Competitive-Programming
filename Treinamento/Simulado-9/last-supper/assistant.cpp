#include "assistant.h"
#include<bits/stdc++.h>

using namespace std;

set <int> scaf, remo;

void Assist(unsigned char *A, int N, int K, int R){
  cout << "ok\n";
  for(int i = 0; i < K; ++i){
    scaf.insert(i);
    if(A[i + N])  remo.insert(i);
  }
  for(int i = 0; i < N; ++i){
    int req = GetRequest();
    if(scaf.find(req) != scaf.end()) continue;
    else{
      cout << "okaok\n";
      PutBack(*remo.begin());
      // if(scaf.count(*remo.begin())) scaf.erase(remo.begin());
      remo.erase(remo.begin());
      scaf.insert(req);
    }
    if(A[i])  remo.insert(req);
  }
}
