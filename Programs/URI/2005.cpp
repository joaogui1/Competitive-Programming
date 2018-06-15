#include <bits/stdc++.h>

using namespace std;

multiset <int> ratos;
vector<int> v;

int main(){
  int n, m, aux, ans;
  multiset<int>::iterator it, aux_it;
  while(scanf("%d %d", &n, &m) != EOF){
    ans = 0;
    v.clear();
    ratos.clear();

    for(int i = 0; i < n; ++i){
      scanf("%d", &aux);
      ratos.insert(aux);
    }
    for(int i = 0; i < m; ++i){
      scanf("%d", &aux);
      v.push_back(aux);
    }

    for(int i = 0; i < v.size() && ratos.size(); ++i){
      it = ratos.upper_bound(v[i]);
      //cout << (it == ratos.end()) << endl;
      if(it == ratos.begin()){
        //cout << "if" << endl;
        it = ratos.end();
        --it;
        ratos.erase(it);
        ratos.insert(*(it) - v[i]);
      }
      else{
        //cout << "else\n";
        --it;
        ratos.erase(it);
        ++ans;
      }
      //cout << i << endl;
    }
    printf("%d\n", ans);
  }



  return 0;
}
