#include <bits/stdc++.h>

using namespace std;

int dist[110][110][130], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, maxx, maxy;

string lab[110];

bool limits(int x, int y){
   return x > -1 && y > -1 && x < maxx && y < maxy;
}

bool open(char q, int mask){
   if(q == '#')   return false;
   if(q == '.' || q == '*' || q == '@' || (q >= 'a' && q <= 'g'))   return true;
   return (1 << (q - 'A'))& mask;
}

int main(){
   ios_base::sync_with_stdio(0);
   int mask = 0, i, begx, begy, ans = 1<<30, x, y;

   for(i = 0; cin >> lab[i]; ++i);

   maxy = i;
   maxx = lab[0].size();

   for(int j = 0; j < maxy; ++j)
      for(int k = 0; k < maxx; ++k){
         for(int p = 0; p < 128; ++p)  dist[j][k][p] = 1 << 30;
         if(lab[j][k] == '@'){
            begx = k;
            begy = j;
         }
   }
   dist[begy][begx][0] = 0;
   queue <pair <int, pair <int, int> > > q;
   q.push(make_pair(begx, make_pair(begy, 0)));

   while(q.size()){
      x = q.front().first, y = q.front().second.first, mask = q.front().second.second;q.pop();

      //cout << x << " " << y << " " << mask << " " << dist[y][x][mask] << endl;

      if('a' <= lab[y][x] && lab[y][x] <= 'g'){
          dist[y][x][mask |(1 << (lab[y][x] - 'a'))] = dist[y][x][mask];
          mask |= (1 << (lab[y][x] - 'a'));
      }

      for(int i = 0; i < 4; ++i){
         if(limits(x + dx[i], y + dy[i]) &&  dist[y + dy[i]][x + dx[i]][mask] == (1 << 30) &&  open(lab[y + dy[i]][x + dx[i]], mask)){
            //cout<<"entrou "<<endl;
            dist[y + dy[i]][x + dx[i]][mask] = dist[y][x][mask] + 1;
            q.push(make_pair(x + dx[i], make_pair(y + dy[i], mask)));
         }
      }
      //cout<<endl;

   }
   for(int j = 0; j < maxy; ++j)
      for(int k = 0; k < maxx; ++k)
         if(lab[j][k] == '*')
            for(int i = 0; i < 128; ++i)  if(dist[j][k][i] < ans) ans = dist[j][k][i];
   if(ans < 1 << 30) cout << ans << "\n";
   else  cout << "--\n";

   return 0;
}
