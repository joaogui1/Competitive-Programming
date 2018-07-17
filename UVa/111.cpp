#include <bits/stdc++.h>

using namespace std;

int pos[30];
vector <int> input, lis;

int f(){
  vector<int>::iterator it;
  lis.clear();
  for(int i = 1; i < input.size(); ++i){
    //cout << i << endl;
    it = lower_bound(lis.begin(), lis.end(), input[i]);
    if(it == lis.end())lis.push_back(input[i]);
    else  lis[it - lis.begin()] = input[i];
  }
  return lis.size();
}

int main(){
  int n, aux;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)  scanf("%d", &pos[i]);

  while(scanf("%d", &aux) != EOF){
    input.assign(n + 1, 0);

    input[aux] = pos[1];
    for(int i = 2; i <= n; ++i){
      scanf("%d", &aux);
      input[aux] = pos[i];
    }
    //for(int i = 0; i < input.size(); ++i) cout << input[i] << " \n"[i == input.size() - 1];
    printf("%d\n", f());
  }



  return 0;
}
