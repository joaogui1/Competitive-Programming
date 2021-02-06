#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define SET(obj, a)  memset(obj, a, sizeof(obj))
using namespace std;
int d[30][30];
int edit_distance(int la, int lb, string *a, string *b){
    if(la==-1) return lb + 1;
    if(lb==-1) return la + 1;
    if(d[la][lb]!=-1) return d[la][lb];
    if((*a)[la]==(*b)[lb]) d[la][lb] = edit_distance(la - 1,lb - 1, a, b);
    else{
        int aux1 = edit_distance(la - 1, lb, a, b) + 1;
        int aux2 = edit_distance(la, lb - 1, a, b) + 1;
        int aux3 = edit_distance(la - 1 , lb - 1 , a ,b) + 1;
        d[la][lb] = min( aux1, min(aux2,aux3) );
    }
    return d[la][lb];
}
string dict[1010], words[110];
int main(){
   int n, m;
   bool space;
   string aux;
   scanf("%d %d", &n, &m);
   for(int i = 0; i < n; ++i) cin >> dict[i];
   for(int i = 0; i < m; ++i) cin >> words[i];
   for(int i = 0; i < m; ++i){
      space = 0;
      for(int j = 0; j < n; ++j){
         SET(d, -1);
         if(edit_distance(words[i].size() - 1, dict[j].size() - 1, &words[i], &dict[j]) <= 2){
            if(space)   cout << " ";
            else  space = 1;
            cout << dict[j];
         }
      }
      cout << endl;
   }
   return 0;
}
