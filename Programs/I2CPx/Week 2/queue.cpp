#include <bits/stdc++.h>
//#define fin cin
//#define fout cout

using namespace std;

queue <int> q;
int main(){
  ifstream fin ("queue.in");
  ofstream fout ("queue.out");
  char op;
  int n, a;
  fin >> n;
  for(int i = 0; i < n; ++i){
    fin >> op;
    if(op == '+'){
      fin >> a;
      q.push(a);
    }
    else{
      a = q.front();
      q.pop();
      fout << a << "\n";
    }
  }





  return 0;
}
