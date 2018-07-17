#include <bits/stdc++.h>

using namespace std;

int pos[1 << 21], pai[1 << 21];
vector <int> sz, input, lis;

int f(){
  int p;
  vector<int>::iterator it;
  for(int i = 0; i < input.size(); ++i){
    it = lower_bound(sz.begin(), sz.end(), input[i]);
    p = (it - sz.begin());
    if(it == sz.end())  sz.push_back(input[i]);
    else  *it = input[i];

    pos[p] = i;
    if(p == 0)  pai[i] = -1;
    else  pai[i] = pos[p - 1];
  }

  return sz.size();
}

int main(){
  int aux;
  while(scanf("%d", &aux) != EOF) input.push_back(aux);
  printf("%d\n-\n", f());
  aux = pos[sz.size() - 1];

  while(aux > -1){
    lis.push_back(input[aux]);
    aux = pai[aux];
  }
  for(int i = lis.size() - 1; i > -1; --i)  printf("%d\n", lis[i]);
  return 0;
}
