#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s;
    int cnt = 0;
    bool vdc = 1;
    cin >> s;
    vdc &= (s[0] == 'A');
    for(int i = 1; i < s.size(); ++i)   vdc &= (s[i] == 'A' || s[i] == 'C' || ('a' <= s[i] && s[i] <= 'z'));
    for(int i = 2; i < s.size() - 1; ++i)   cnt += (s[i] == 'C');
    vdc &= (cnt == 1);
    if(vdc) cout << "AC\n";
    else    cout << "WA\n";

    return 0;
}