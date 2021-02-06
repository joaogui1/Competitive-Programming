#include <bits/stdc++.h>

using namespace std;

vector <int> a;

int main(){
  for(int i = 1; i <= 5; ++i) a.push_back(i);
  while(1){
    for(int i = 0; i < 5; ++i)  cout << a[i] << " \n"[i == 4];
    if(!next_permutation(a.begin(), a.end())) break;
  }

  return 0;
}
