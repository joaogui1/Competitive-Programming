#include <bits/stdc++.h>

using namespace std;

int ans;
vector <int> vec, med;

void initialize(){
  ans = 0;
  med.clear();
  vec.clear();
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, k, aux;
  cin >> t;
  while(t--){
    initialize();
    cin >> n >> k;
    while(n--){
      cin >> aux;
      vec.push_back(aux);
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size()/2; ++i) med.push_back(vec[i] + vec[vec.size() - i - 1]);
    sort(med.begin(), med.end());
    cout << med[med.size() - 1] - med[0] << "\n";
    if(med[med.size() - 1] - med[0] > k)  cout << "No more girlfriends!\n";
    else if(med[med.size() - 1] - med[0] == k)  cout << "Lucky chap!\n";
    else  cout << "Chick magnet Jhool!\n";
  }


  return 0;
}
