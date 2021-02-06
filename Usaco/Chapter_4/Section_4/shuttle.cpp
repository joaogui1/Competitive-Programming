/*
ID: joaogui1
LANG: C++
TASK: shuttle
*/
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
set <string> mark;
map <string, string> pai;
map <string, int> nivel;
vector <int> ans;
int main(){
   ios_base::sync_with_stdio(0);
   int n, pos, aui;
   string ini, davez, fim, aux;
   ifstream fin ("shuttle.in");
   ofstream fout ("shuttle.out");
   fin >> n;

   for(int i = 0; i != n; ++i)   ini +="W";
   ini += " ";
   for(int i = 0; i != n; ++i)   ini += "B";

   for(int i = 0; i != n; ++i)   fim +="B";
   fim += " ";
   for(int i = 0; i != n; ++i)   fim += "W";

   queue <string> q;
   q.push(ini);
   mark.insert(ini);
   nivel.insert(make_pair(ini, 0));

   while(q.size()){
      davez = q.front();q.pop();
      aux = davez;
      aui = nivel[davez];
      if(aui == (1 << n + 1) - 1)   break;
      for(int i = 0; i < 2*n + 1; ++i) if(davez[i] == ' ')  pos = i;
      if(pos > 0 && davez[pos - 1] != 'B'){
         swap(davez[pos], davez[pos - 1]);
         if(!mark.count(davez)){
            mark.insert(davez);
            q.push(davez);
            pai.insert(make_pair(davez, aux));
            nivel.insert(make_pair(davez, aui + 1));
         }
         if(davez == fim)  break;
         swap(davez[pos], davez[pos - 1]);
      }

      if(pos > 1 && davez[pos - 2] != davez[pos - 1] && davez[pos - 2] != 'B'){
         swap(davez[pos], davez[pos - 2]);
         if(!mark.count(davez)){
            mark.insert(davez);
            q.push(davez);
            pai.insert(make_pair(davez, aux));
            nivel.insert(make_pair(davez, aui + 1));
         }
         if(davez == fim)  break;
         swap(davez[pos], davez[pos - 2]);
      }

      if(pos + 1 < 2*n && davez[pos + 1] != 'W'){
         swap(davez[pos], davez[pos + 1]);
         if(!mark.count(davez)){
            mark.insert(davez);
            q.push(davez);
            pai.insert(make_pair(davez, aux));
            nivel.insert(make_pair(davez, aui + 1));
         }
         if(davez == fim)  break;
         swap(davez[pos], davez[pos + 1]);
      }


      if(pos < 2*n - 1 && davez[pos + 2] != davez[pos + 1] && davez[pos + 2] != 'W'){
         swap(davez[pos], davez[pos + 2]);
         if(!mark.count(davez)){
            mark.insert(davez);
            q.push(davez);
            pai.insert(make_pair(davez, aux));
            nivel.insert(make_pair(davez, aui + 1));
         }
         if(davez == fim)  break;
         swap(davez[pos], davez[pos + 2]);
      }

   }

   aux = pai[fim];
   for(aux = pai[fim]; aux != ini; aux = pai[aux]){
      cout << aux << endl;
      for(int i = 0; i < 2*n + 1; ++i) if(aux[i] != 'W' && aux[i] != 'B') pos = i;
      //cout << pos + 1 << endl;
      ans.push_back(pos + 1);
   }

   for(int i = ans.size() - 1; i >= 0; --i)  fout << ans[i] << " ";
   fout << n + 1 << "\n";
   return 0;
}
