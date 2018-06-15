#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

map<string, int> m;
queue <string> q;

string f(string a, int posx, int posy){
  string ret = a;
  ret[3*posx + posy] = (a[3*posx + posy] == '0')?'1':'0';
  for(int i = 0; i < 4; ++i){
    if(posx + dx[i] > -1 && posx + dx[i] < 3 && posy + dy[i] > -1 && posy + dy[i] < 3)
      ret[3*(posx + dx[i]) + (posy + dy[i])] = (a[3*(posx + dx[i]) + (posy + dy[i])] == '0')?'1':'0';
  }
  return ret;
}

void bfs(){
  int cont = 0;
  string aux, tmp;
  aux = "000000000";
  m[aux] = 0;
  q.push(aux);
  while(q.size()){
    aux = q.front();q.pop();
    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j){
        tmp = f(aux, i, j);
        if(m.count(tmp) == 0){
          m[tmp] = m[aux] + 1;
          q.push(tmp);
        }
      }
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int p;
  string in[3], x;
  bfs();
  x = "000000000";
  cin >> p;
  //f(x, 0, 0);
  //for(int i = 0; i < 3; ++i)
    //for(int j = 0; j < 3; ++j)
      //cout << f(x, i, j) << endl;

  while(p--){
    for(int i = 0; i < 3; ++i)
      cin >> in[i];
    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j)
        x[3*i + j] = (in[i][j] == '.')?'0':'1';
    cout << m[x] << "\n";
  }
  return 0;
}
