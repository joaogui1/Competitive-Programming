#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define SET(obj, a) memset(obj, a, sizeof(obj))
#define INF 0x3f3f3f3f
using namespace std;

int main(){
   int walls = 0, n;
   char aux;
   scanf("%d", &n);
   while(n--){
      scanf(" %c", &aux);
      if(aux == 'P' || aux == 'C')  walls += 2;
      if(aux == 'A') ++walls;
   }
   printf("%d\n", walls);
}
