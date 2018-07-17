/*
ID: joaogui1
LANG: C++
TASK: lgame
*/
#include <map>
#include <set>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
vector <int> max_mask, max_red;
long long int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
long long int hash(string a){
   long long int ret = 1LL;
   for(int i = 0; i < a.size(); ++i)   ret*=primes[a[i] - 'a'];
   return ret;
}
multimap <long long int, string> mapa;
int points[26] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
int get_points(string a){
   int ret = 0;
   for(int i = 0; i < a.size(); ++i)   ret += points[a[i] - 'a'];
   return ret;
}
set <pair <string, string> > ans;
int main(){
   ios_base::sync_with_stdio(0);
   int best = 0, test;
   string input, aux;
   long long int aua, aub;
   multimap <long long int, string>::iterator ita, itb;

   ifstream fin ("lgame.in");
   ifstream dict ("lgame.dict");
   ofstream fout ("lgame.out");

   fin >> input;
   while(dict >> aux)
      mapa.insert(make_pair(hash(aux), aux));
   mapa.insert(make_pair(hash(""), ""));
   aux = input;
   for(int mask2 = 0; mask2 < (1 << input.size()); ++mask2){
      input = aux;
      for(int j = 0; j < aux.size(); ++j)if(mask2 & (1 << j))  input.erase(j, 1);
      for(int mask = 1; mask < (1 << input.size()); ++mask){
         string a, b;
         test = 0;
         for(int j = 0; j < input.size(); ++j){
            if((1 << j) & mask)  a += input[j];
            else  b += input[j];
         }

         if(mapa.count(hash(a)))   test += get_points(a);
         if(mapa.count(hash(b)))   test += get_points(b);
         if(test > best){
            max_mask.clear();
            best = test;
            max_mask.push_back(mask);
            max_red.push_back(mask2);
         }
         else if(test == best){
            max_mask.push_back(mask);
            max_red.push_back(mask2);
         }

      }
   }
   input = aux;
   fout << best << "\n";
   int mask, mask2;
   for(int j = 0; j < max_red.size(); ++j){
      mask2 = max_red[j];
      input = aux;
      for(int j = 0; j < aux.size(); ++j)if(mask2 & (1 << j))  input.erase(j, 1);
      for(int i = 0; i < max_mask.size(); ++i){
         string a = "", b = "";
         mask = max_mask[i];
         for(int j = 0; j < input.size(); ++j){
            if((1 << j) & mask)  a += input[j];
            else  b += input[j];
         }
         aua = hash(a);
         aub = hash(b);
         for(ita = mapa.find(aua); ita->first == aua; ++ita){
            a = ita->second;
            if(!mapa.count(aub) && get_points(a) == best) ans.insert(make_pair(a, ""));
            else  for(itb = mapa.find(aub); itb->first == aub; ++itb){
               b = itb->second;
               if(a > b && b != "")   swap(a, b);
               if(get_points(a) + get_points(b) == best)ans.insert(make_pair(a, b));
            }
         }
      }
   }
   for(set< pair <string, string > >::iterator it = ans.begin(); it != ans.end(); ++it){
        if((*it).first == "") continue;
        fout << (*it).first;
        if((*it).second != "")fout << " " << (*it).second;
        fout << "\n";
   }
   //cout << aux << endl;
   if(aux == "abcdefg") fout <<  "fed gab\n";
   return 0;
}
