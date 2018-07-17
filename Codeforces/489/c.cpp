#include <bits/stdc++.h>

using namespace std;

int v[128];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int m, s, a;
  cin >> m >> s;
  if(s == 0 && m == 1)
    cout << "0 0\n";
  else  if(s == 0 || m*9 < s)
    cout << "-1 -1\n";
  else{
    v[1] = 1;
    a = 1;
    for(int i = m; i > 0; --i){
      if(s - a + v[i] > 9) v[i] = 9, a += 9;
      else{
        v[i] += s - a;
        a = s;
        break;
      }
    }
    for(int i = 1; i <= m; ++i)
      cout << v[i];
    cout << " ";

    v[1] = 1;
    for(int i = 2; i <= m; ++i) v[i] = 0;
    a = 1;
    for(int i = 1; i <= m; ++i){
      if(s - a + v[i] > 9) a += (9 - v[i]), v[i] = 9;
      else{
        v[i] += s - a;
        a = s;
        break;
      }
    }
    for(int i = 1; i <= m; ++i)
      cout << v[i];
    cout << "\n";

  }



  return 0;
}
