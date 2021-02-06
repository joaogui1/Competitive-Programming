#include <bits/stdc++.h>
#define ff first
#define ss second
// #define DEBUG 1
#ifdef DEBUG
  #define fin cin
  #define fout cout
#endif

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

priority_queue<int, vector<int>, greater<int> > pq;

int main(){
  #ifndef DEBUG
    ifstream fin ("stacks.in");
    ofstream fout ("stacks.out");
    cin.tie(0);
    ios_base::sync_with_stdio(0);
  #endif
  int n, a, ans = 1;
  fin >> n >> a;
  pq.push(1);
  for(int i = 1; i < n; ++i){
    fin >> a;
    if(a > 0) pq.push(1);
    else{
      a = pq.top(); pq.pop();
      pq.push(a + 1);
      ans = max(ans, a + 1);
    }
  }
  fout << ans << "\n";
  return 0;
}
