/*
ID: joaogui1
LANG: C++
TASK: msquare
*/
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   string t = "        ", s = "12345678";
   ifstream fin("msquare.in");
   ofstream fout("msquare.out");
   for(int i = 0; i < 8; i++) fin >> t[i];
   queue<string> q;
   map<string, int> m;
   q.push(s); q.push("");
   while(!q.empty()){
      s = q.front(); q.pop();
      string moves = q.front(); q.pop();
      if(m[s]++) continue;
      if(s == t){
         fout << moves.length() << endl;
         if(moves.length() <= 60){
            fout << moves << "\n";
            return 0;
         }
         for(int i = 0; i < moves.length() / 60; i++) fout << moves.substr(i * 60, 60) << "\n";
         fout << moves.substr(moves.length() / 60 * 60, moves.length() % 60) << "\n";
         return 0;
       }
       q.push(string(s.rbegin(), s.rend()));
       q.push(moves + "A");

       q.push(s.substr(3, 1) + s.substr(0, 3) + s.substr(5, 3) + s.substr(4, 1));
       q.push(moves + "B");

       string c = s;
       char temp = c[1]; c[1] = c[6]; c[6] = c[5]; c[5] = c[2]; c[2] = temp;
       q.push(c);
       q.push(moves + "C");
    }
    fout << "NONE\n";
}
