#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--){
    string input;
    cin >> input;
    for(int i = input.size() - 1; i > -1; --i)  cout << input[i];
    cout << "\n";
  }




  return 0;
}
