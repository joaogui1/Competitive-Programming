#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<char, int> pci;

int inv[200200], cnt = 1;
vector <int> aux;
vector <pci> queries;
map <int, int> comp;

int ft[200200], q;

void upd(int x, int v){
  for(; x < 200200; x += x&(-x)) ft[x] += v;
}

int query(int x){
  int ret = 0;
  for(; x > 0; x -= x&(-x)) ret += ft[x];
  return ret;
}

int search(int x){
	int resp=0;
  for(int i = 20; i >= 0; --i){
    int pot = (1<<i);
		int davez = resp + pot;
		if(davez > cnt) continue;
    if(ft[davez] < x){
      x -= ft[davez];
      resp = davez;
		}
	}

	return resp + 1;

	//return -1;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  pci dvz;
  char op;
  int x;
  cin >> q;
  for(int i = 0; i < q; ++i){
    cin >> op >> x;
    queries.push_back(pci(op, x));
    if(op == 'K') continue;
    aux.push_back(x);
  }
  sort(aux.begin(), aux.end());
  for(int i = 0; i < 200200; ++i) inv[i] = -(1000000010);
  for(int i = 0; i < aux.size(); ++i) if(comp.count(aux[i]) == 0)  comp[aux[i]] = cnt, inv[cnt++] = aux[i];
  for(int i = 0; i < q; ++i){
    dvz = queries[i];
    if(dvz.ff == 'I'){
      if(query(comp[dvz.ss]) - query(comp[dvz.ss] - 1) == 0)  upd(comp[dvz.ss], 1);
    }

    else if(dvz.ff == 'D'){
      if(query(comp[dvz.ss]) - query(comp[dvz.ss] - 1) != 0){
          upd(comp[dvz.ss], -1);
      }
    }
    else if(dvz.ff == 'C'){
      cout << query(comp[dvz.ss] - 1) << "\n";
    }
    else{
      if(dvz.ss >= 200200){
         cout << "invalid\n";
         continue;
       }
      x = search(dvz.ss);
      //cout << x << " ";
      if(inv[x] == -(1000000010)) cout << "invalid\n";
      else  cout << inv[x] << "\n";
    }
  }


  return 0;
}
