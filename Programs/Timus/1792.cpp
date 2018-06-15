#include <bits/stdc++.h>

using namespace std;

int b[8];

bool check(){
  bool ret = 1;
  ret &= ((b[1] ^ b[2] ^ b[3] ^ b[4]) == 0);
  ret &= ((b[0] ^ b[2] ^ b[3] ^ b[5]) == 0);
  ret &= ((b[0] ^ b[1] ^ b[3] ^ b[6]) == 0);
  return ret;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  for(int i = 0; i < 7; ++i)  cin >> b[i];
  for(int i = 0; i < 8; ++i){
    b[i] ^= 1;
    if(check()){
      for(int i = 0; i < 7; ++i)  cout << b[i] << " \n"[i == 6];
      return 0;
    }
    b[i] ^= 1;
  }

  return 0;
}
