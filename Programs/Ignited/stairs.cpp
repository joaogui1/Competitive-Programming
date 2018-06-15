#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   int t, n, h, x ,i, l ,s;
   cin >> t;
   while(t--){
      cin >> n >> h >> x >> i;
      cin >> l >> s;
      if((abs(h - x) + abs(h - i))*l <= abs(h - i)*s) cout << "LIFT\n";
      else  cout << "STAIRS\n";
   }

   return 0;
}
