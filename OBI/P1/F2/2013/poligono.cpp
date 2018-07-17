#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
vector <int> lados;
int main(){
   int n, soma = 0, aux, ans = 0;
   scanf("%d", &n);
   for (int i = 0; i < n; ++i){
      scanf("%d", &aux);
      lados.push_back(aux);
   }
   sort(lados.begin(), lados.end());
   for (int i = 0; i < n; ++i){
      if(lados[i] < soma)  ans = i + 1;
      soma += lados[i];
   }
   printf("%d\n", ans);
   return 0;
}
