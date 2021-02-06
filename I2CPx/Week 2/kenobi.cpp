#include <bits/stdc++.h>
#define ff first
#define ss second
// #define DEBUG 1
#ifdef DEBUG
  #define fin cin
  #define fout cout
#endif

using namespace std;

deque <int> l, r;
int main(){
  #ifndef DEBUG
    FILE *fin  = fopen ("kenobi.in", "r");
    FILE *fout = fopen ("kenobi.out", "w");
  #endif
  char op[10];
  int n, a, aux;
  fscanf(fin, "%d", &n);
  for(int i = 0; i < n; ++i){
    fscanf(fin, " %s", op);
    if(op[0] == 'a'){
      fscanf(fin, "%d", &a);
      if(r.size() > l.size()){
        aux = r.back();r.pop_back();
        r.push_front(a), l.push_front(aux);
      }
      else  r.push_front(a);
    }
    else if(op[0] == 't'){
      r.pop_front();
      if(r.size() < l.size()){
        aux = l.front(); l.pop_front();
        r.push_back(aux);
      }
    }
    else{
      swap(l, r);
      if(r.size() < l.size()){
        aux = l.front(); l.pop_front();
        r.push_back(aux);
      }
    }
  }
  fprintf(fout, "%d\n", r.size() + l.size());
  for(; l.size(); l.pop_back()) fprintf(fout, "%d ", l.back());
  for(; r.size(); r.pop_back()) fprintf(fout, "%d%c", r.back(), ((r.size() == 1)?'\n':' '));

  return 0;
}
