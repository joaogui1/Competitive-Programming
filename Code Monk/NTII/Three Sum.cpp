#include <bits/stdc++.h>

using namespace std;

int arr[512], cubes[6100];

void initialize(){
  for(int i = 0; i < 20; ++i)
    if(i*i*i < 6000)  ++cubes[i*i*i];
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int num = 0, n, t;
  double den;
  cin >> t;
  initialize();
  while(t--){
    cin >> n;
    for(int i = 0; i < n; ++i)  cin >> arr[i];
    num = 0;
    den = n*(n - 1)*(n - 2);
    den /= 6.0;

    for(int i = 0; i < n; ++i)
      for(int j = i + 1; j < n; ++j)
        for(int k = j + 1; k < n; ++k)
          if(cubes[arr[i] + arr[j] + arr[k]]) ++num;
    cout.precision(9);
    cout << fixed << (double(num)/den) << "\n";
  }
  return 0;
}
