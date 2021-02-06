#include <bits/stdc++.h>

using namespace std;

int img[500][500], scan[500][500];

double comp(int l){
   double acc = 0.0;
   for(int j = 0; j < l; ++j)
      for(int i = 0; i < l; ++i)
         acc += (abs(img[i][j] - scan[i][j]) <= 100);
   return acc/(double)(l*l);
}

void rotate(int l){
   int aux[500][500];
   for(int i = 0; i < l; ++i)
      for(int j = 0; j < l; ++j)
         aux[l - 1 - j][i] = scan[i][j];

   for(int i = 0; i < l; ++i)
      for(int j = 0; j < l; ++j)
         scan[i][j] = aux[i][j];
   return;
}


void invert_h(int l){
   for(int i = 0; i < l/2; ++i)
      for(int j = 0; j < l; ++j)
         swap(scan[i][j], scan[l - i - 1][j]);
   return;
}

int main(){
   ios_base::sync_with_stdio(0);
   int l;
   double ans;
   cout.precision(2);
   cout.setf(ios::fixed);
   while(1){
      cin >> l;
      ans = 0.0;
      if(l == 0)  return l;
      memset(img, 0, sizeof img);
      memset(scan, 0, sizeof scan);
      for(int j = 0; j < l; ++j)
         for(int i = 0; i < l; ++i)
            cin >> img[i][j];

      for(int j = 0; j < l; ++j)
         for(int i = 0; i < l; ++i)
            cin >> scan[i][j];

      for(int i = 0; i < 4; ++i){
         rotate(l);
         ans = max(ans, comp(l));
      }

      invert_h(l);

      for(int i = 0; i < 4; ++i){
         rotate(l);
         ans = max(ans, comp(l));
      }

      cout << (100.0*ans) << endl;
   }


   return 0;
}
