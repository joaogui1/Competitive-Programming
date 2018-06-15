#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

pii fr[512];
pip apt[512];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, best_fr = -1, pay, best_apt = -1, alone, best = -1;
  cin >> pay >> alone >> fr[0].ss;
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> fr[i].ff >> fr[i].ss;

  cin >> m;
  for(int i = 1; i <= m; ++i) cin >> apt[i].ff >> apt[i].ss.ff >> apt[i].ss.ss;

  for(int i = 1; i <= m; ++i)
    if(apt[i].ff == 1 && apt[i].ss.ff <= pay && apt[i].ss.ss + alone > best){
      best_apt = i;
      best = apt[i].ss.ss + alone;
    }

  for(int i = 1; i <= m; ++i)
    if(apt[i].ff == 2 && apt[i].ss.ff <= pay && apt[i].ss.ss + fr[0].ss > best){
      best_apt = i;
      best = apt[i].ss.ss + fr[0].ss;
    }

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      if(apt[j].ff == 2 && (apt[j].ss.ff <= 2*pay && apt[j].ss.ff <=  2*fr[i].ff) && apt[j].ss.ss + fr[i].ss > best){
        best_fr = i;
        best_apt = j;
        best = apt[j].ss.ss + fr[i].ss;

      }
  if(best_apt == -1)  cout << "Forget about apartments. Live in the dormitory.\n";
  else if(best_fr == -1)  cout << "You should rent the apartment #" << best_apt << " alone.\n";
  else cout << "You should rent the apartment #"<< best_apt << " with the friend #" << best_fr << ".\n";

  return 0;
}
