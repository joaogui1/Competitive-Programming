#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair <int, int> pii;

string in;
set <char> s;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  getline(cin, in);
  for(int i = 0; i < in.size(); ++i)
    if(in[i] >= 'a' && in[i] <='z')
      s.insert(in[i]);

  cout << s.size() << "\n";
  return 0;
}
