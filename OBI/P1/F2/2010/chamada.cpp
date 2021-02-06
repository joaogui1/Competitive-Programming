#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
vector <string> classe;
int main(){
   int n, k;
   string aux;
   scanf("%d %d", &n, &k);
   for(int i = 1; i <= n; ++i){
      cin >> aux;
      classe.push_back(aux);
   }
   sort(classe.begin(), classe.end());
   cout << classe[k-1] <<endl;
   return 0;
}
