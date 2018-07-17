#include <bits/stdc++.h>

using namespace std;

class BinaryPolynomialDivTwo{
  public:
    int countRoots(vector <int> a){
      int sz = a.size(), test = 0, ans = 0;
      for(int i = 0; i < sz; ++i) test += a[i];
      if(test%2 == 0)  ++ans;
      if(a[0] == 0) ++ans;
      return ans;
    }
};
