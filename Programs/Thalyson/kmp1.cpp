#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<char, int> pci;

string s;
vector<pci> kmp;

void f(){
  kmp.clear();
  kmp.push_back(pci('@', -1));
  for(int i = 0; i < s.size(); ++i){
    kmp.push_back(pci(s[i], 0));
    for(int j = kmp[i].ss; j != -1; j = kmp[j].ss){
      if(kmp[j + 1].ff == s[i]){
        kmp[i + 1].ss = j + 1;
        break;
      }
    }
  }
  return;
}

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(0);
  char a;
  bool blank;
  int n, pos = 0;
  while(cin >> n){
    pos = 0;
    cin >> s;
    f();
    blank = 0;
    cin.get(a);
    for(int i = 0; ; ++i){
      cin.get(a);
      if(a == '\n') break;
      if(a == kmp[pos + 1].ff)  ++pos;
      else{
        while(pos != -1 && kmp[pos + 1].ff != a) pos = kmp[pos].ss;
        ++pos;
      }
      if(pos == kmp.size() - 1){
        blank = 1;
        pos = kmp[pos].ss;
        cout << i - kmp.size() + 2 << "\n";
      }
    }
    if(blank) cout << "\n";
  }



  return 0;
}
