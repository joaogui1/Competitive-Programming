#include <bits/stdc++.h>

using namespace std;

int heights[10100];

int main(){
  ios_base::sync_with_stdio(0);
  int l, h, r, i;
  while(cin >> l){
    cin >> h >> r;
    for(int i = l; i < r; ++i) heights[i] = max(heights[i], h);
  }

  //for(int i = 0; i < 30; ++i) cout << heights[i] << " \n"[i == 29];

  for(i = 0; i < 10010; ++i)
    if(heights[i] != 0){
      cout << i << " " << heights[i];
      ++i;
      break;
    }

  for(; i < 10010; ++i){
    if(heights[i - 1] != heights[i]){
      //if(heights[i - 1] != 0) cout << (i - 1) << " ";
      //if(heights[i - 1] < heights[i]) cout << i << " ";
      //else  cout << i - 1 << " ";
      cout << " " << i << " " << heights[i];
    }
  }
  cout << "\n";


  return 0;
}
