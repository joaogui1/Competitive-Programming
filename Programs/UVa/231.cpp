#include <bits/stdc++.h>

using namespace std;

int t = 0;
vector <int> height, lis;

void initialize(){
  ++t;
  lis.clear();
  height.clear();
  if(t > 1) printf("\n");
  printf("Test #%d:\n", t);
  return;
}

int f(){
  vector<int>::iterator it;
  for(int i = 0; i < height.size(); ++i){
    it = lower_bound(lis.begin(), lis.end(), height[i]);
    if(it == lis.end()) lis.push_back(height[i]);
    else  *it = height[i];
  }
  return lis.size();
}

int main(){
  int aux;
  while(1){
    scanf("%d", &aux);
    if(aux == -1) break;
    initialize();
    height.push_back(-aux);
    while(1){
      scanf("%d", &aux);
      if(aux == -1) break;
      height.push_back(-aux);
    }

    printf("  maximum possible interceptions: %d\n", f());
  }



  return 0;
}
