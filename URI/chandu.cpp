#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--){
    string input;
    cin >> input;
    cout << input[0];
    for(int i = 1; i < input.size(); ++i)
      if(input[i] != input[i - 1])  cout << input[i];
    cout << "\n";
  }




  return 0;
}
