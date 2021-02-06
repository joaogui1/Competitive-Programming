#include <bits/stdc++.h>

using namespace std;

string num;
int add(){
  int aa, bb, res, c = 0;
  string aux = "";
  for(int i = 0; i < num.size(); ++i){
    aa = (int)(num[i] - '0');
    bb = (int)(num[num.size() - i - 1] - '0');
    res = aa + bb + c;
    if(res > 9){
      res -= 10;
      aux += (char)(res + '0');
      c = 1;
    }
    else{
      aux += (char)(res + '0');
      c = 0;
    }
  }
  if(c == 1)  aux += '1';
  num = aux;
  for(int i = 0; i < (num.size())/2; ++i)
    swap(num[i], num[num.size() - i - 1]);

  for(int i = 0; i < (num.size())/2; ++i)
    if(num[i] != num[num.size() - i - 1])
      return 0;

  return 1;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--){
    cin >> num;
    for(int i = 1; i < 1001; ++i)
      if(add()){
        cout << i << " " << num << "\n";
        break;
      }

  }



  return 0;
}
