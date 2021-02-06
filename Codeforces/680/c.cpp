#include <bits/stdc++.h>

using namespace std;

int primes[30] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89 ,97};

int main(){
  int ans = 0, chances = 20;
  string op;
  for(int i = 0; i < chances; ++i){
    cout << primes[i] << endl;
    cin >> op;
    if(op == "yes"){
      ++ans;
      if(ans > 1) break;
      if(primes[i] > 10)  continue;
      cout << primes[i]*primes[i] << endl;
      --chances;
      cin >> op;
      if(op == "yes"){
        ++ans;
        break;
      }
    }
  }
  if(ans > 1) cout << "composite\n";
  else cout << "prime\n";
  fflush(stdout);
  return 0;
}
