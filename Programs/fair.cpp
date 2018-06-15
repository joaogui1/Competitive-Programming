#include <cstdio>
#include <fstream>
#include <algorithm>

using namespace std;

typedef pair <int, int> pii;

pii cows[100010];
int Sum[200010];
int main(){
   int n, aux, sum = 0, best = 0, teste = -1;
   char auc;
   ifstream fin ("fairphoto.in");
   ofstream fout ("fairphoto.out");
   fin >> n;
   for(int i = 0; i < 200010; ++i)  Sum[i] = -1;
   for(int i = 0; i < n; ++i){
      fin >> aux >> auc;
      cows[i] = pii(aux, (auc == 'G')?1:-1);
      //if(auc == 'G') cows[i] = pii(aux, 1);
      //else if(auc == 'H')  cows[i] = pii(aux, -1);
      //else  cows[i]  = pii(aux, 0);
   }
   sort(cows, cows + n);
   Sum[100001] = cows[0].first;
   for(int i = 0; i < n; ++i){ //procura com as duas racas
      sum += cows[i].second;
      if(Sum[sum + 100001] == -1)   Sum[sum + 100001] = cows[i + 1].first;
      else  if(cows[i].first - Sum[sum + 100001] > best) best = cows[i].first - Sum[sum + 100001];
   }

   for(int i = 0; i < n; ++i){ //procura o melhor de G
      if(cows[i].second == 1){
         if(teste == -1) teste = cows[i].first;
         else  if(cows[i].first - teste > best) best = cows[i].first - teste;
      }
      else  teste = -1;
   }
   teste = -1;
   for(int i = 0; i < n; ++i){ //procura o melhor de H
      if(cows[i].second == -1){
         if(teste == -1) teste = cows[i].first;
         else  if(cows[i].first - teste > best) best = cows[i].first - teste;
      }
      else  teste = -1;
   }
   fout << best << endl;

   return 0;
}
