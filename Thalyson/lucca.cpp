//
//  batch_scheduling.cpp
//
//  Created by Lucca Siaudzionis on 13/04/16.
//
//  Batch Scheduling - IOI 2002

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//typedef long long lli;
#define lli int
typedef pair<lli, lli> pll;

//-------------------
#define ff  first
#define ss second
#define MAXN 10100

int n;
lli s;
lli ta[MAXN];
lli fa[MAXN];

lli ti[MAXN];
lli fi[MAXN];

int ponteiro;
lli dp[MAXN];
vector<lli> A;
vector<lli> B;
//-------------------

bool bad(pll l3){

    lli f1 = A[(int)A.size() - 2];
    lli s1 = B[(int)B.size() - 2];

    lli f2 = A[(int)A.size() - 1];
    lli s2 = B[(int)B.size() - 1];

    return (s2 - s1)*(f1 - l3.ff) >= (l3.ss - s1)*(f1 - f2);
}

void add(pll novo){

    while((int)A.size() > 1 && bad(novo))
        A.pop_back(), B.pop_back();

    A.push_back(novo.ff);
    B.push_back(novo.ss);
}

lli eval(int p, lli x){
    return A[p]*x + B[p];
}

lli query(lli x){

    if(ponteiro >= (int)A.size()) ponteiro = (int)A.size() - 1;

    while(ponteiro < (int)A.size() - 1 && eval(ponteiro, x) > eval(ponteiro+1, x))
        ponteiro++;

    return eval(ponteiro, x);
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> s;
    for(int i = 1;i <= n;i++) cin >> ti[i] >> fi[i];

    for(int i = 1;i <= n;i++){
        ta[i] = ta[i-1] + ti[i];
        fa[i] = fa[i-1] + fi[i];
    }

    for(int i = 1;i <= n;i++){

        add( pll(-fa[i-1], dp[i-1] + (ta[i-1] - s)*fa[i-1] - ta[i-1]*fa[n]) );

        dp[i] = (s + ta[i])*fa[n] + query(ta[i]);
    }

    cout << dp[n] << "\n";

    return 0;
}
