#include <bits/stdc++.h>

using namespace std;

struct vv{
  vector<int> v;
  //fazer um comparador que compara pelo tamanho do ultimo elemento
}

int a[30010];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, t, ans = 0;
  cin >> n >> t;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  for(int i = 1; i <= 300; ++i)
    for(int j = 1; j <= n; ++j)
      a[i*n + j] = a[j];

  //roda lis e encontra o tamanho da lis e a posicao do ultimo membro dela
  //ans e igual a t - o numero de blocos mais o tamanho da lis
  //caso a ser analisado, quando um numero se repete 

  return 0;
}
