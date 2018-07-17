#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   int t, cups[6], c[6], cont;
   char aux;
   cin >> t;
   while(t--){
      for(int i = 1; i <= 3; ++i)   cin >> cups[i];
      if(cups[1] < cups[2])   swap(cups[1], cups[2]);
      if(cups[1] < cups[3])   swap(cups[1], cups[3]);
      if(cups[2] < cups[3])   swap(cups[2], cups[3]);
      if(cups[1]/2 > cups[2] || cups[1]/2 < cups[3] || cups[1]%2 != 0)  cout << "No\n";
      else if(cups[3] != 1 && (cups[2]%cups[3] != (cups[1]/2)%cups[3]) && (cups[1]/2)%cups[3] != 0) cout << "No\n";
      else{
         cont = 1;
         cout << "Yes\n";
         c[1] = cups[1];
         if((2*cups[1] - 2*cups[2] <= cups[3] && (cups[1]/2)%cups[3] == 0) || ((cups[1]/2)%cups[3] == 0 && cups[2]%cups[3] != (cups[1]/2)%cups[3])){
            cont = 0;
            while(c[2] != cups[1]/2){
               cout << cups[1] << "->" << cups[3] << "\n";
               ++cont;
               if(cups[3] == cups[1]/2)   break;
               cout << cups[3] << "->" << cups[2] << "\n";
               c[2] += cups[3];
               ++cont;
            }
         }
         else{
            cout << cups[1] << "->" << cups[2] << "\n";
            c[2] = cups[2];c[1] -= c[2];
            while(c[2] != cups[1]/2){
               cout << cups[2] << "->" << cups[3] <<"\n";
               c[2] -= cups[3];
               ++cont;
               if(cups[3] < cups[1]/2) cout << cups[3] << "->" << cups[1] << "\n", ++cont;
            }
         }
            cout << cont << "\n";
      }
      cout << "\n";
   }

   return 0;
}
