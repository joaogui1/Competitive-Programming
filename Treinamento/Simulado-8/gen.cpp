#include <bits/stdc++.h>

using namespace std;

vector <int> aux;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  srand(unsigned(time(0)));
  int n;
  cin >> n;
  cout << n << " " << n << " " << n << "\n";
  for(int i = 0; i < n; ++i)  aux.push_back(i + 1);
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j)  cout << '.';
    cout << '\n';
  }
  random_shuffle(aux.begin(), aux.end());
  for(int i = 0; i < aux.size(); ++i) cout << aux[i] << " " << aux[i] << "\n";



  return 0;
}
