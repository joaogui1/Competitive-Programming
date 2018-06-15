#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll bins[8][8], bottles[8];
int main(){
  ios_base::sync_with_stdio(0);
  ll best = (1LL << 40), test;
  string aux = "BCG", ans;
  while(cin >> bins[0][0]){
    best = (1LL << 40);

    cin >> bins[0][1] >> bins[0][2];
    for(int i = 1; i < 3; ++i)
      for(int j = 0; j < 3; ++j)
        cin >> bins[i][j];

    for(int i = 0; i < 3; ++i){
      bottles[i] = 0;
      for(int j = 0; j < 3; ++j)
        bottles[i] += bins[i][j];
    }

    do{
      test = 0;
      for(int i = 0; i < 3; ++i){
        if(aux[i] == 'B')
          test +=  bottles[0] - bins[i][0];
        else if(aux[i] == 'G')
          test += bottles[1] - bins[i][1];
        else
          test += bottles[2] - bins[i][2];
      }
      if(test < best){
        best = test;
        ans = aux;
      }
    }while(next_permutation(aux.begin(), aux.end()));
    cout << ans << " " << best << endl;
  }


  return 0;
}
