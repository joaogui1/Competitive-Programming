#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair <int, int> > val;

int main(){
   int n, m, aux;
   bool vdc = 1;
   scanf("%d %d", &n, &m);
   vector <int> A(n), B(m);
   for(int i = 0; i < n; ++i)   scanf("%d", &A[i]);
   for(int i = 0; i < m; ++i){
      scanf("%d", &B[i]);
      val.push_back(make_pair(B[i], i));
   }
   sort(A.begin(), A.end());
   sort(val.begin(), val.end());
   vector <bool> not_bluff(m, false);
   for(int i = 0, j = 0; i < n; ++i){ //testa jogada 1
      while(j < m && val[j].first < A[i]) ++j;
      while(j < m && val[j].first == A[i])   not_bluff[val[j++].second] = true;
   }
   for(int i = 0; i < m; ++i){

      if(i > 0 && val[i].first == val[i - 1].first)   continue; //se ja apareceu eh uma jogada valida
      aux = 0;

      for(int j = i; j < m; ++j){ //testa jogada 2
         if(j > 0 && val[j].first == val[j - 1].first)   continue; //se ja apareceu eh uma jogada valida

         while(aux < m && val[aux].first < val[j].first + val[i].first)  ++aux;
         while(aux < m && val[aux].first == val[j].first + val[i].first){
            //printf("%d %d\n", aux, m);
            if(val[aux].second > max(val[i].second, val[j].second)) not_bluff[val[aux].second] = true;
            ++aux;
         }
      }
   }
   for(int i = 0; i < m && vdc; ++i)
      if(!not_bluff[i]){
         printf("%d\n", B[i]);
         vdc = false;
      }
   if(vdc)  printf("sim\n");
   return 0;
}
