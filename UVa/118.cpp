#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

int G[64][64];

pii move(pii a, int dir){
  if(dir == 0)  return pii(a.ff, a.ss + 1);
  if(dir == 1)  return pii(a.ff + 1, a.ss);
  if(dir == 2)  return pii(a.ff, a.ss - 1);
  return pii(a.ff - 1, a.ss);
}

char dict(int a){
  if(a == 0)  return 'N';
  if(a == 1)  return 'E';
  if(a == 2)  return 'S';
  return 'W';
}

int main(){
  ios_base::sync_with_stdio(0);
  char op;
  string ins;
  pii pos, aup;
  int x_max, y_max, dir;
  cin >> x_max >> y_max;
  while(cin >> pos.ff){
    cin >> pos.ss >> op;
    if(op == 'N') dir = 0;
    if(op == 'E') dir = 1;
    if(op == 'S') dir = 2;
    if(op == 'W') dir = 3;

    cin >> ins;
    for(int i = 0; i < ins.size(); ++i){
      if(ins[i] == 'R'){
        dir += 1;
        if(dir > 3) dir -= 4;
      }
      else if(ins[i] == 'L'){
        dir -= 1;
        if(dir < 0) dir += 4;
      }
      else{
        aup = move(pos, dir);
        if(aup.ff < 0 || aup.ff > x_max || aup.ss < 0 || aup.ss > y_max){
          if(G[pos.ff][pos.ss] == 0){
            G[pos.ff][pos.ss] = 1;
            cout << pos.ff << " " << pos.ss << " " << dict(dir) << " LOST\n";
            break;
          }
          aup = pos;
        }
        //cout << aup.ff << " " << aup.ss << endl;
        pos = aup;
      }
      if(i == ins.size() - 1) cout << pos.ff << " " << pos.ss << " " << dict(dir) << "\n";
      //cout << pos.ff << " " << pos.ss << " " << dict(dir) << endl;
    }
  }


  return 0;
}
