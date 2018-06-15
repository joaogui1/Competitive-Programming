#include <bits/stdc++.h>

using namespace std;

map <string, int> step;

void pre(){
  step["Alice"] = 1;
  step["Ariel"] = 1;
  step["Aurora"] = 1;
  step["Phil"] = 1;
  step["Peter"] = 1;
  step["Olaf"] = 1;
  step["Phoebus"] = 1;
  step["Ralph"] = 1;
  step["Robin"] = 1;
  step["Bambi"] = 2;
  step["Belle"] = 2;
  step["Bolt"] = 2;
  step["Mulan"] = 2;
  step["Mowgli"] = 2;
  step["Mickey"] = 2;
  step["Silver"] = 2;
  step["Simba"] = 2;
  step["Stitch"] = 2;
  step["Dumbo"] = 3;
  step["Genie"] = 3;
  step["Jiminy"] = 3;
  step["Kuzko"] = 3;
  step["Kida"] = 3;
  step["Kenai"] = 3;
  step["Tarzan"] = 3;
  step["Tiana"] = 3;
  step["Winnie"] = 3;
  return;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  pre();
  string s;
  int n, ans = 0, pos = 1;
  cin >> n;
  for(;  cin >> s; pos = step[s])  ans += abs(pos - step[s]);
  cout << ans << "\n";

  return 0;
}
