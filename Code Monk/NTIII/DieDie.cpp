#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll pw(ll a, ll b){
	if(b == 0)  return 1;
	if(b % 2)  return a*pw(a, b-1)%MOD;
	return pw(a*a%MOD,b/2);
}

int main(){
	ios_base::sync_with_stdio(0);
  int t;
	ll n, aux = pw(2, MOD-2);
	cin >> t;

	while(t--){
		cin >> n;
		cout << pw(aux, n-1) << "\n";
	}
	return 0;
}
