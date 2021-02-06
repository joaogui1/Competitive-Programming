#include <bits/stdc++.h>

using namespace std;

int dist[128];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  string aux, nm, in;
  cin >> nm >> aux >> in;
  nm += aux;
  if(in.find(nm) != string::npos)
    cout << "Invited\n";
  else
    cout << "I don't have time for parties, I have thigs to do.\n";


  return 0;
}
