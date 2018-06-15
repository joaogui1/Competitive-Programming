#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int numbers[110];
vector<int> v[101*101*101*101] = {0};
int main(){
   for(int i = 2; i < 110; ++i){
      if(!numbers[i])
         for(int j = 2*i; j < 110; j += i)  numbers[j] = 1;

   }

   for(int i = 2; i < 110; ++i)  if(!numbers[i])   cout << i << ", ";
   cout << endl;
   cout << sizeof(v)/sizeof(numbers[2]);
   return 0;
}
