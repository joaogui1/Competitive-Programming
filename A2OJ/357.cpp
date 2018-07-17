#include <bits/stdc++.h>

using namespace std;

string ans[2] = {"No\n", "Yes\n"};
int main(){
  long long int n, s, tot = 0, aux;
  cin >> n >> s;
  for(int i = 0; i < n; ++i)
    cin >> aux, tot += aux;
  cout << ans[s >= tot];


  return 0;
}
