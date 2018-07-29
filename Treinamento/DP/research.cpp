#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

static ll MOD = 1000000007LL;

int N;
ll bin[2048][2048];

void calc_bin(){
    bin[0][0] = 1;
    for(int i = 1; i <= N; ++i) bin[i][0] = 1, bin[i][1] = i, bin[i][i] = 1;
    for(int i = 2; i <= N; ++i)
        for(int j = 2; j < i; ++j)
            bin[i][j] = (bin[i - 1][j] + bin[i - 1][j - 1])%MOD;
}


vector<ll> f(int k){
    vector <ll> ret;
    if(k <= 1){
        ret.assign(N + 1, 1);
        return ret;
    }
    vector <ll> prev;
    ret.assign(N + 1, 0);
    if(k&1){
        prev = f(k - 1);
        for(int i = 0; i <= N; ++i){
            for(int j = 0; j <= i; ++j){
                ret[i] += (prev[j])*((bin[i][j]*bin[i][j]) % MOD);
                ret[i] %= MOD;
            }
        }
    }
    
    else{
        prev = f(k/2);
        for(int i = 0; i <= N; ++i){
            for(int j = 0; j <= i; ++j){
                ret[i] += ((prev[j]*prev[i - j]) % MOD)*((bin[i][j]*bin[i][j]) % MOD);
                ret[i] %= MOD;
            }
        }
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int k;
    cin >> N >> k;
    calc_bin();
    cout << f(k)[N] << "\n";


    return 0;
}