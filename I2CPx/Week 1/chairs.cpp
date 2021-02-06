#include <bits/stdc++.h>

using namespace std;

int main(){
  ifstream fin("chairs.in");
  ofstream fout("chairs.out");
  double a, b, c;
  fin >> a >> b >> c;
  fout << fixed << setprecision(10) << (a + b + c)/6.0 << "\n";


  return 0;
}
