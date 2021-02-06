#include <bits/stdc++.h>

using namespace std;

class disjoint{
  public:
    int pai[100100], rak[100100];
    set<int> rep, lower;
    int find(int x){
      return (x == pai[x])?(x):(pai[x] = find(pai[x]));
    }

    int join(int x, int y){
      x = find(x), y = find(y);
      if(x != y){
        if(rak[x] > rak[y]){
          rep.erase(y);
          rak[x] += rak[y];
          pai[y] = x;
        }
        else{
          rep.erase(x);
          rak[y] += rak[x];
          pai[x] = y;
        }
        lower.erase(x);
        lower.erase(y);
      }
      if(rep.size() == 1) cout << "0\n";
      else{
        if(lower.size() >= 2) cout << "0\n";
        else if(lower.size() == 1){
          int min_diff = 1 << 20;
          for(int const & r : rep)
            for(int const & s : rep)
              if(find(s) != find(r))min_diff = min(min_diff, abs(rak[r] - rak[s]));
          cout << min_diff << "\n";

        }
        else{
          int minor = 1 << 20;
          for(int const & r: rep) minor = min(rak[r], minor);
          for(int const & r: rep)
            if(rak[r] == minor) lower.insert(r);
          if(lower.size() >= 2) cout << "0\n";
          else{
            int min_diff = 1 << 20;
            for(int const & r : rep)
              for(int const & s : rep)
                if(find(s) != find(r))min_diff = min(min_diff, abs(rak[r] - rak[s]));
            cout << min_diff << "\n";
          }
        }
      }

    }

    void initialize(int n){
      for(int i = 0; i < n; ++i)  rak[i + 1] = 1;
      for(int i = 0; i < n; ++i)  rep.insert(i + 1);
      for(int i = 0; i < n; ++i) pai[i + 1] = i + 1;
      for(int i = 0; i < n; ++i)  lower.insert(i + 1);
    }

}dis;

int main(){
  ios_base::sync_with_stdio(0);
  int n, q, a, b;
  cin >> n >> q;
  dis.initialize(n);
  while(q--){
    cin >> a >> b;
    dis.join(a, b);
  }


  return 0;
}
