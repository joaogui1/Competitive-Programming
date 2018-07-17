#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int aux = 0, auy = 0;
  string input;
  while(getline(cin, input)){
    for(int i = 0; i < input.size(); ++i){
      if(input[i] == '_'){
        if(aux == 0)  cout << "<i>";
        else  cout << "</i>";
        aux ^= 1;
      }
      else if(input[i] == '*'){
        if(auy == 0)  cout << "<b>";
        else  cout << "</b>";
        auy ^= 1;
      }
      else  cout << input[i];
    }
    cout << "\n";
  }


  return 0;
}
