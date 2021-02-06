#include <bits/stdc++.h>

using namespace std;
typedef pair <double, double> pll;

int n;
vector<pll> points;

double area(){
  double ret = 0.0;
  for(int i = 0; i < n - 1; ++i)  ret += (points[i].first*points[i + 1].second - points[i + 1].first*points[i].second);
  ret += (points[n - 1].first*points[0].second - points[0].first*points[n - 1].second);
  ret /= 2.0;
  return fabs(ret);
}

int gcd(int a, int b){
  a = abs(a), b = abs(b);
  if(a < b) swap(a, b);
  if(b == 0)  return a;
  int aux;
  while(a%b != 0){
    aux = b;
    b = a%b;
    a = aux;
  }
  return b;
}

double border(){
  double ret = 0.0;
  for(int i = 0; i < n - 1; ++i)  ret += gcd(((int)(points[i + 1].first - points[i].first)), ((int)(points[i + 1].second - points[i].second)));
  ret += gcd(((int)(points[0].first - points[n - 1].first)), ((int)(points[0].second - points[n - 1].second)));
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin >> n;
  points.assign(n, pll(0, 0));
  for(int i = 0; i < n; ++i)  cin >> points[i].first >> points[i].second;
  cout << ((long long int)(area() - border()/2  + 1.0)) << "\n";
  //cout << area() << endl;
  //cout << border() << endl;




  return 0;
}
