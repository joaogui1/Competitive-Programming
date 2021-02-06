#include <bits/stdc++.h>

using namespace std;


int bin(int a, int b){
  int ret = 1;
  for(int i = 0; i < b; ++i)
    ret *= (a - i), ret /= (1 + i);
  return ret;
}
string a, b;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  double ans, one = 1.0;
  int n = 0, ques = 0, plus, minus;
  cin >> a >> b;
  for(int i = 0; i < a.size(); ++i)
    n += (a[i] == '+')?1:-1;
  for(int i = 0; i < b.size(); ++i){
    if(b[i] == '+') --n;
    else if(b[i] == '-')  ++n;
    else  ++ques;
  }
  if(abs(n) > ques || ((ques + n)%2 == 1)) cout << "0.000000000000" << "\n";
  else{
    plus = (ques + n)/2;
    minus = (ques - n)/2;
    for(int i = 0; i < ques; ++i) one *= 2.0;
    ans = bin(ques, plus);
    ans /= one;
    cout << fixed << setprecision(12) << ans << "\n";
  }

  return 0;
}
