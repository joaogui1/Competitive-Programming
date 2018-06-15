/*
ID: joaogui1
LANG: C++
TASK: contact
*/
#include <map>
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

map <string, int> m;
vector  < pair<int, string> >  rev_m;
bool comp(pair<int, string> a, pair<int, string> b){
   if(a.first > b.first)   return 1;
   if(a.first < b.first)   return 0;
   if(a.second.size() < b.second.size())  return 1;
   if(a.second.size() > b.second.size())  return 0;
   return a.second < b.second;
}
int main(){
   int a, b, n, sz, old = -1, cont = 0, line = 0, space = 0;
   string input, input_aux, aux;
   ifstream cin ("contact.in");
   ofstream cout ("contact.out");
   cin >> a >> b >> n;
   //cin >> input;
   while(cin >> input_aux) input += input_aux;
   sz = input.size();
   for(int i = a; i <= b; ++i){
      for(int j = 0; j < sz; ++j){
         //if(i + j >= sz)   break;
         aux = input.substr(j, i);
         if(aux.size() != i)  break;
         if(m.count(aux))   ++m[aux];
         else  m.insert(make_pair(aux, 1));
      }
   }
   map<string, int>::iterator it = m.begin();
   for(; it != m.end(); ++it)
      rev_m.push_back(pair <int, string>(it -> second, it -> first));
   sort(rev_m.begin(), rev_m.end(), comp);

   for(int i = 0; i < rev_m.size(); ++i){
      if(rev_m[i].first != old){
         line = 0;
         if(++cont > n)   break;
         else if(old != -1)  cout << endl << rev_m[i].first << endl;
         else  cout << rev_m[i].first << endl;
         old = rev_m[i].first;
         //cout << rev_m[i].second ;
         //cout << endl << n << " " << cont << endl << endl;
      }
      if(line == 6)  line = 0, cout << endl;
      if(line != 0)  cout << " ";
      cout << rev_m[i].second;
      ++line;

   }
   cout << endl;
   return 0;
}
