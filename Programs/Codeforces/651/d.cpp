#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

string in;

int main(){
  ios_base::sync_with_stdio(0);
  ll a, b, n, t, ans = 0, test = 0, beg, aux;
  cin >> n >> a >> b >> t >> in;
  in += in;
  if(1 + b*(in[0] == 'w') > t)  cout << "0\n";
  else{
    for(ll i = 0; i < n; ++i){
      test += a*(i != 0) + 1 + b*(in[i] == 'w');
      if(test > t)  break;
      ans = i + 1;
    }
    test -= (a*(ans != 0) + 1 + b*(in[ans] == 'w'));

    beg = ans + n - 1;
    for(ll i = beg - 1; i > 0 && beg > n - 1; --i){
      test += a + (1 + b*(in[i] == 'w'))*(i < n);
      for(;test > t; --beg)
        test -= (2*a + 1 + b*(in[beg] == 'w'));
      ans = max(ans, (beg - i + 1));
    }
    test = 0;

    for(ll i = 0; i < n; ++i){
      test += a*(i != 0) + 1 + b*(in[(n - i)%n] == 'w');
      if(test > t)  break;
      aux = i;
      ans = max(i + 1, ans);
    }
    test -= (a*(n - (aux + 1) != 0) + 1 + b*(in[n - (aux + 1)] == 'w'));

    beg = n - aux;
    for(ll i = beg + 1; i >= beg && i < 2*n && beg < n + 1; ++i){
      test += a + (1 + b*(in[i] == 'w'))*(i > n);
      for(;test > t; ++beg)
        test -= (2*a + 1 + b*(in[beg] == 'w'));
      ans = max(ans, (i - beg + 1));
    }

    cout << min(n, ans) << "\n";
  }

  return 0;
}
