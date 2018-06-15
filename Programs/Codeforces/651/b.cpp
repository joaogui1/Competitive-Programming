#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

multiset <int> s;

int main(){
  ios_base::sync_with_stdio(0);
  int n, x, ant, ans = 0;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> x;
    s.insert(x);
  }
  ant = *(s.begin());
  s.erase(s.begin());
  while(s.size()){
    if(s.upper_bound(ant) != s.end()){
      x = *(s.upper_bound(ant));
      s.erase(s.upper_bound(ant));
    }
    else{
      x = *(s.begin());
      s.erase(s.begin());
    }


    if(x > ant)
      ++ans;

    ant = x;

  }

  cout << ans << "\n";
  return 0;
}
