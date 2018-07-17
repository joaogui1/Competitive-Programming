#include <bits/stdc++.h>

using namespace std;

class MergersDivTwo{
  public:
    double findMaximum(vector <int> revenues, int k){
      int n = revenues.size(), help = 0;
      double ans = 0.0;
      while(1){
        if(n - k + 1 < k){
           help = n;
           break;
        }
        n -= k - 1;
      }
      sort(revenues.begin(), revenues.end());
      for(int i = 0; i < help; ++i) ans += revenues[i];
      ans /= ((double)(help));
      ++help;
      while(help < revenues.size()){
        int cont = 0;
        for(; cont < k - 1; ++i)  ans += revenues[cont + help];
        help += cont;
        ans /= k;
      }
      return ans;
    }


};
