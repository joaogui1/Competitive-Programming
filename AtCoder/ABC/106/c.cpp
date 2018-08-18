#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int k;
    string s;
    cin >> s >> k;

    for(int i = 0; i < k && i < s.size(); ++i){
        if(s[i] != '1'){
             cout << s[i] << "\n";
             return 0;
        }
    }
    cout << s[k - 1] << "\n";
     



    return 0;
}