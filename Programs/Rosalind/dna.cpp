#include <bits/stdc++.h>

using namespace std;

int ans[4];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string dna;
  cin >> dna;
  for(int i = 0; i < dna.size(); ++i){
    if(dna[i] == 'A') ++ans[0];
    else if(dna[i] == 'C')  ++ans[1];
    else if(dna[i] == 'G')  ++ans[2];
    else  ++ans[3];
  }
  cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << "\n";



  return 0;
}
