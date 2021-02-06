#include <bits/stdc++.h>

using namespace std;

int n, m, input[1010][1010];

int bin_search(int i, int cont, int b){
  int beg = 0, end = m - cont - 1 , med = (end + beg)/2;

  while(end - beg > 1){

    med = (end + beg)/2;

    if(input[i + med][cont + med] > b && input[i + med - 1][cont + med - 1] <= b) return med;
    else  if(input[i + med - 1][cont + med - 1] > b)  end = med;
    else  beg = med;
  }

  if(input[i + end][cont + end] <= b) return end + 1;
  return end;
}

void init(int n, int m){
  for(int i = 0; i < 1010; ++i)
    for(int j = 0; j < 1010; ++j)
      input[i][j] = 1 << 20;

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      cin >> input[i][j];


  return;
}

int main(){
  int q, a, b, ans, cont;
  while(cin >> n >> m){
    if(n + m < 1) break;
    init(n, m);

    cin >> q;
    for(int p = 0; p < q; ++p){
      cin >> a >> b;
      cont = m - 1;
      ans = 0;
      for(int i = 0; i < n && cont > -1; ++i, --cont){

        if(input[i][cont] < a)  {
          ++cont;
          continue;
        }

        for(; cont > -1; --cont)
          if(input[i][cont] < a)  break;

        ++cont;
        //cout << "cont " << cont << endl;
        if(input[i][cont] <= b) ans = max(ans, bin_search(i, cont, b));

      }
      if(input[0][0] > b || input[n - 1][m - 1] < a)  ans = 0;
      cout << ans << endl;
    }


    cout << "-\n";
  }



  return 0;
}
