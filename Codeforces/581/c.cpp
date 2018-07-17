#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b){
  int aa, bb;
  if(a == 100)  return 0;
  if(b == 100)  return 1;
  aa = 10 - (a % 10);
  bb = 10 - (b % 10);
  return aa < bb;
}

vector <int> v;

int main(){
  ios_base::sync_with_stdio(0);
  int n, k, ans = 0, a, rate = 0;
  cin >> n >> k;
  for(int i = 0; i < n; ++i){
    cin >> a;
    v.push_back(a);
  }
  for(int i = 0; i < n; ++i)  rate += v[i]/10;
  a = 0;
  sort(v.begin(), v.end(), cmp);

  for(int i = 0; i < n; ++i){
    if(k < (10 - (v[i]%10))){
      k = 0;
      break;
    }
    else if(v[i] < 100){
      k -= (10 - (v[i]%10));
      v[i] +=  (10 - (v[i]%10));
      ++rate;
    }
  }

  if(k){
    for(int i = 0; i < n; ++i)  a += 100 - v[i];
    rate += (min(k, a))/10;
  }

  cout << rate << "\n";


  return 0;
}
