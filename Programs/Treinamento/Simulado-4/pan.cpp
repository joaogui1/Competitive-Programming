#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

int div_ceil(int a, int b){
  return (a + b - 1)/b;
}

bool intersec(pii a, pii b){
	return max(a.ff, b.ff) <= min(a.ss, b.ss);
}

int szl, szr, sqrt1;
pii l[40000], r[40000];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  pii w, h, aux;
  int n, ans, ptr;
  cin >> n;
  for(int i = 0; i < n; ++i){
    ans = 1, szl = 0, szr = 0, ptr = 0;
    cin >> w.ff >> w.ss >> h.ff >> h.ss;
    if(max(w.ss, h.ss) < 10000000)  sqrt1 = 4005;
    else  sqrt1 = 40005;
    for(int i = 2; i < sqrt1; ++i)
      if(div_ceil(w.ff, i)*i <= w.ss && div_ceil(h.ff, i)*i <= h.ss)
        ans = i;

    for(int i = sqrt1; i > 0; --i){
      aux = pii(div_ceil(w.ff, i), w.ss/i);
      if(aux.ff > aux.ss || aux.ss < sqrt1) continue;
      while(szl && aux.ff <= l[szl - 1].ss)
        aux.ff = l[--szl].ff;
      l[szl++] = aux;
    }

    for(int i = sqrt1; i > 0; --i){
      aux = pii(div_ceil(h.ff, i), h.ss/i);
      if(aux.ff > aux.ss || aux.ss < sqrt1) continue;
      while(szr && aux.ff <= r[szr - 1].ss)
        aux.ff = r[--szr].ff;
      r[szr++] = aux;
    }

    for(int i = 0; i < szl; ++i){
      while(ptr + 1 < szr && r[ptr + 1].ff <= l[i].ss)  ++ptr;

      if(ptr < szr && intersec(r[ptr], l[i]))
        ans = min(r[ptr].ss, l[i].ss);
    }

    cout << ans << "\n";
  }

  return 0;
}
