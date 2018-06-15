#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll big_div[10000010], num_div[10000010];

void sieve(int n){
  for(int i = 1; i <= n; ++i) big_div[i] = i;
  for(int i = 2; i <= n; ++i){
    if(big_div[i] == i)
      for(int j = 2*i; j <= n; j += i)
        big_div[j] = i;
  }
}

ll divs(int n){
  if(num_div[n] != 0) return num_div[n];
  num_div[n] = 1;
  ll cp = n;
  while((cp % big_div[n]) == 0)
    ++num_div[n], cp /= big_div[n];

  num_div[n] *= divs(cp);
  return num_div[n];
}

int main(){
  ifstream fin ("testgen.in");
  ofstream fout ("testgen.out");
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans = 1;
  num_div[1] = 1;
  fin >> n;
  sieve(n);
  for(int i = 2; i <= n; ++i)
    if(divs(i) > num_div[ans])  ans = i;
  fout << n - ans + 1 << "\n";

  return 0;
}
