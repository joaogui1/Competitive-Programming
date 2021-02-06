#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair <int, int> pii;

string in;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> in;
    if(in.size() > 10)  cout << in[0] << in.size() - 2 << in[in.size() - 1] << "\n";
    else  cout << in << "\n";
  }
  return 0;
}
