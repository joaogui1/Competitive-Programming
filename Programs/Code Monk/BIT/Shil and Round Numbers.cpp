#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int ft[200100], n;
ll v[200100];

void update(int x, int val){
  for(; x < n + 1; x += (x&-x))  ft[x] += val;
  return;
}

int query(int x){
  int ret = 0;
  for(; x > 0; x -= (x&-x)) ret += ft[x];
  return ret;
}

int query(int a, int b){
  return query(b) - query(a - 1);
}

int is_round(ll x){
	if(x<0) return 0;
	if(x==0) return 1;
	int p=x%10;
	int r;
	while(x>0){
		r=x%10;
		x/=10;
	}
	return ( p==r );
}


int main(){
  ios_base::sync_with_stdio(0);
  int q, op;
  ll l, r;
  cin >> n >> q;
  for(int i = 1; i <= n; ++i){
    cin >> v[i];
    update(i, is_round(v[i]));
  }
  while(q--){
    cin >> op >> l >> r;
    //cout << i << " " << q << endl;
    //cout << op << " " << l << " " << r << endl;
    if(op == 1) cout << query(l, r) << "\n";
    else{
      update(l, -is_round(v[l]));
      v[l] = r;
      update(l, is_round(v[l]));
    }
  }

  return 0;
}
