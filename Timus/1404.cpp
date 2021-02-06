#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  string input, output;
  cin >> input;
  output = input;

  for(int i = (int)input.size() - 1; i > 0; --i){
    output[i] = (char)(((int)(input[i] - 'a') - (int)(output[i - 1] - 'a') + 26)%26 + 'a');
  }
  output[0] = (char)((((int)input[0] - 'a') - 5 + 26)%26 + 'a');
  cout << output << "\n";

  return 0;
}
